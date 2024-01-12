#include <fstream>
#include <boost/functional/hash.hpp>
#include <unordered_map>

#include "athena/utils.h"
#include "poseidon/geo_point.h"

namespace athena {
    bool parse_baidu_apollo_map(std::string& file_path,
                                apollo::hdmap::Map& map) {
        std::fstream input(file_path, std::ios::in | std::ios::binary);
         if (!input) {
            std::cerr << "Failed to open " << file_path << std::endl;
            return false;
        }
        apollo::hdmap::Map map;
        if (!map.ParseFromIstream(&input)) {
            std::cerr << "Failed to parse map." << std::endl;
            return false;
        }
        return true;
    }

    bool construct_graph(const apollo::hdmap::Map& map,
                        std::vector<athena::Node>& nodes,
                        std::vector<athena::Edge>& edges) {
        // 直接在这定义计算 graph id 的匿名函数不就行了
        auto tile_level = TileHierachy::levels().back();
        auto predict_graph_id = [&tile_level](const poseidon::WGS84Point& point) {
            return tile_level.GetGraphId(point, tile_level.level);
        }
        std::unordered_map<uint64_t, size_t> edge_dict;
        auto saveRelations = [&nodes, &edges](apollo::hdmap::Id from,
                                              apollo::hdmap::Id to,
                                              poseidon::WGS84Point& cursor_loc,
                                              bool from_is_cursor,
                                              bool isLaneChange) {
            uint64_t seed_forward = 0;
            boost::hash_combine(seed_forward, from.id());
            boost::hash_combine(seed_forward, to.id());
            auto edge_searcher = edge_dict.find(seed_forward);
            if (edge_searcher == edge_dict.end()) {
                // 不存在，需要新建一个边
                athena::Edge edge;
                edge_dict[seed_forward] = edges.size();
                edges.push_back(edge);
                auto& back_element = edge.back();
                back_element.forwardAccess = true;
                back_element.isLaneChange = isLaneChange;
                
                // 添加点
                nodes.emplace_back(from.id());
                nodes.back().setStartOf(edges.size() - 1);
                // 需要添加坐标点，后期用于分配到对应的tile中
                if (from_is_cursor) {
                    node.back().setPoint(cursor_loc);
                    node.back().setGraphId(predict_graph_id(cursor_loc));
                }

                nodes.emplace_back(to.id());
                nodes.back().setEndOf(edges.size() - 1);
                if (!from_is_cursor) {
                    nodes.back().setPoint(cursor_loc);
                    node.back().setGraphId(predict_graph_id(cursor_loc));
                }
                
            } else {
                // 存在，需要更新边的信息
                edges[edge_searcher->second].forwardAccess = true;
            }

            // 反向的同步也得更新：
            uint64_t seed_reverse = 0;
            boost::hash_combine(seed_reverse, to.id());
            boost::hash_combine(seed_reverse, from.id());
            auto edge_searcher = edge_dict.find(seed_reverse);
            if (edge_searcher == edge_dict.end()) {
                // 不存在，需要新建一个边
                athena::Edge edge;
                edge_dict[seed_reverse] = edges.size();
                edges.push_back(edge);
                auto& back_element = edge.back();
                back_element.reverseAccess = true;
                back_element.isLaneChange = isLaneChange;

                // 添加点
                nodes.emplace_back(to.id());
                nodes.back().setStartOf(edges.size() - 1);
                if (!from_is_cursor) {
                    nodes.back().setPoint(cursor_loc);
                    node.back().setGraphId(predict_graph_id(cursor_loc));
                }
                nodes.emplace_back(from.id());
                nodes.back().setEndOf(edges.size() - 1);
                if (from_is_cursor) {
                    node.back().setPoint(cursor_loc);
                    node.back().setGraphId(predict_graph_id(cursor_loc));
                }
            } else {
                // 存在，需要更新边的信息，正反交叉赋值，没问题
                edges[edge_searcher->second].reverseAccess = true;
            }
        };
        
        for (size_t i = 0; i < map.lane_size(); ++i) {
            const apollo::hdmap::Lane& lane = map.lane(i);
            // 获取锚点，用于确定处于哪个tile,
            // TODO(sunwei) : 问题在于这里只能获取一个点的坐标，邻居的实际坐标获取不到，所以在同时预测GraphId的时候邻居的就无法预测！
            auto& anchor_point = lane.central_curve().segment(0).start_position();

            // 处理每一个邻接对象，并且保证正反向都保存了，后期通过hash(start, end)来搜索定位
            // predecessor
            for (size_t k = 0; k < lane.predecessor_id_size(); k++) {
                auto predecessor_id = lane.predecessor_id(k);
                saveRelations(predecessor_id, lane.id(), anchor_point, false, false);
            }
            // successor
            for (size_t k = 0; k < lane.successor_id_size(); k++) {
                auto successor_id = lane.successor_id(k);
                saveRelations(lane.id(), successor_id,
                              anchor_point, true, false);
            }
            // left_neighbor_forward
            for (size_t k = 0; k < lane.left_neighbor_forward_lane_id_size(); k++) {
                auto left_neighbor_forward_lane_id =
                    lane.left_neighbor_forward_lane_id(k);
                saveRelations(left_neighbor_forward_lane_id,
                              lane.id(), anchor_point, false, true);
            }
            // right_neighbor_forward
            for (size_t k = 0; k < lane.right_neighbor_forward_lane_id_size(); k++) {
                auto right_neighbor_forward_lane_id =
                    lane.right_neighbor_forward_lane_id(k);
                saveRelations(right_neighbor_forward_lane_id,
                              lane.id(), anchor_point, false, true);
            }
        }

        // 重新刷一边Node,给每个点都填充 graph id以及 coursor location
        std::sort(nodes.begin(), nodes.end(), [](const Node& lhs, const Node& rhs) {
            return lhs.getId() < rhs.getId();
        });

        size_t start_index = 0;
        size_t end_index = 0;
        poseidon::Graphid temp_id;
        poseidon::WGS84Point temp_point;
        while (end_index < nodes.size()) {
            if (nodes[end_index].getId() == nodes[start_index].getId()) {
                if (nodes[end_index].getGraphId().valid()) {
                    temp_id = nodes[end_index].getGraphId();
                    temp_point = nodes[end_index].getPoint();
                }
                end_index++;
            } else {
                // 说明找到了一个新的点
                auto& node = nodes[start_index];
                auto& point = node.getPoint();
                node.setGraphId(predict_graph_id(point));
                
                // 刷新 [start_index, end_indx)之间的元素
                for (size_t i = start_index, i < end_index, i++) {
                    nodes[i].setGraphId(node.getGraphId());
                    nodes[i].setPoint(node.getPoint());
                }
                temp_id.reset();
                temp_point.reset();

                start_index = end_index;
            }
        }

        // 需要验证所有点
        for (auto node : nodes) {
            if (!node.getGraphId().valid()) {
                std::cout << "Failed!!!" << std::endl;
                break;
            }
        }

        return true;
    }
}