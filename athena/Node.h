// Copyright (C) 2023 Olympus Corporation. All rights reserved.

#ifndef NODE_H
#define NODE_H

#include <cstdint>
#include <limits>
#include "poseidon/geo_point.h"
#include "poseidon/grapid.h"

namespace athena {
class Node {
public:
    Node(uint64_t id)
        : id_(id), start_of_(std::numeric_limits<uint64_t>::max()),
            end_of_(std::numeric_limits<uint64_t>::max()) {}

    // 构造函数
    Node(uint64_t id, uint64_t start_of, uint64_t end_of)
        : id_(id), start_of_(start_of), end_of_(end_of) {}

    // 获取 id
    uint64_t getId() const { return id_; }

    // 获取 start_of
    uint64_t getStartOf() const { return start_of_; }

    // 获取 end_of
    uint64_t getEndOf() const { return end_of_; }

    // 设置 start_of
    void setStartOf(uint64_t start_of) { start_of_ = start_of; }

    // 设置 end_of
    void setEndOf(uint64_t end_of) { end_of_ = end_of; }

    void setPoint(const poseidon::WGS84Point& point) { point_ = point; }
    void setPoint(double x, double y, double z) {
        point_.x = x;
        point_.y = y;
        point_.z = z;
    }

    poseidon::WGS84Point getPoint() const { return point_; }



    void setGraphId(const poseidon::Graphid& graph_id) { graph_id_ = graph_id; }
    poseidon::Graphid getGraphId() const { return graph_id_; }

private:
    WGS84Point point_;  // 需要一个具体的点参与 tile 的划分
    uint64_t id_;
    uint64_t start_of_;
    uint64_t end_of_;

    poseidon::Graphid graph_id_;
};
}

#endif // NODE_H