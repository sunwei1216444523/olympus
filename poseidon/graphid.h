#ifndef GRAPH_ID_H
#define GRAPH_ID_H

#include <limits>
#include "graphconstants.h"

namespace poseidon {

struct Graphid {
public:
    constexpr uint64_t kInvalidGraphId = std::numeric_limits<uint64_t>::max();
    constexpr uint64_t kIncreace = 1 << 33;


    /**
     * @brief 通过level, tileid, id构造一个Graphid
     *        具体的字节分配是：
     *        3bit level, 30bit tileid, 31bit id
    */
    uint64_t value;

    Graphid(): value(kInvalidGraphId) {}

    Graphid(uint64_t level, uint64_t tileid, uint64_t id) {
        if (tileid > kMaxGraphTileId) {
        throw std::logic_error("Tile id out of valid range");
        }
        if (level > kMaxGraphHierarchy) {
        throw std::logic_error("Level out of valid range");
        }
        if (id > kMaxGraphId) {
        throw std::logic_error("Id out of valid range");
        }
        value = level | (tileid << 3) | (static_cast<uint64_t>(id) << 33);
    }

    expicit Graphid(uint64_t value) : value(value) {}

    uint32_t level() const {
        return value & 0x7;
    }

    uint32_t tileid() const {
        return (value >> 3) & 0x3fffffff;
    }

    uint32_t id() const {
        return value >> 33;
    }

    Graphid& operator++() {
        value += kIncreace;
        return *this;
    }

    Graphid operator++(int) {
        Graphid temp(*this);
        value += kIncreace;
        return temp;
    }

    void reset() {
        value = kInvalidGraphId;
    }
};
}



#endif // GRAPH_ID_H