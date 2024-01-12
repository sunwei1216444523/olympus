#ifndef GRAPH_CONSTANTS_H
#define GRAPH_CONSTANTS_H

namespace poseidon {
    // graph id max 31bit
    constexpr uint64_t kMaxGraphId = 2147483647;
    // tile id max 30bit
    constexpr uint64_t kMaxGraphTileId = 1073741823;
    // level id max 3bit
    constexpr uint32_t kMaxGraphHierarchy = 7;
}



#endif // GRAPH_CONSTANTS_H