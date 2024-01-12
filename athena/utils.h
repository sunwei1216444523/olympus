#ifndef UTILS_H
#define UTILS_H

#include <cstdint>
#include <vector>
#include "Edge.h"
#include "Node.h"
#include "external/baidu_apollo/modules/map/proto/map.pb.h"

// 序列化暂时不是这里的重点，后期需要的化可以考虑使用flatbuffer，或者直接就protobuffer也行
// 这里直接使用vector记录所有数据。

namespace athena {

    /**
    * @brief 完成Apollo中地图数据的解析
    * @param file_path 地图文件的路径
    * @param map 解析后的地图数据
    */
    bool parse_baidu_apollo_map(std::string& file_path,
                                apollo::hdmap::Map& map);

    /**
    * @brief 根据高精地图数据重新构图
    * @param map 高精地图数据
    * @param nodes 构图后的节点，代表lane对象
    * @param edges 构图后的边，代表lane之间的连接关系
    */
    bool construct_graph(const apollo::hdmap::Map& map,
                        std::vector<athena::Node>& nodes,
                        std::vector<athena::Edge>& edges);

    
}


#endif // UTILS_H