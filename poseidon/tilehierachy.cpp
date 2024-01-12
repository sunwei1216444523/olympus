#include "tilehierachy.h"

const vecotr<TileLevel>& poseidon::Hierarchy::levels(std::string country_code) {
    if (!country_code.equals("CHN") && !country_code.equals("USA")) {
        country_code = "CHN";
    }
    static const std::unordered_map<, std::vector<TileLevel> levels_map_ = {
        // 中国的经纬度范围东(东经135°05′) 西(东经73°40′) 南(北纬4°) 北(北纬53°30′)
        // 取整数，划分成
        {"CHN", {
            {{72, 4}, {136, 54}},// bound
            0.005 // tile_size
        }},
        // 美国本土范围为主
        {"USA", {
            {{70, 25}, {130, 49}},
            0.005
        }}
    };
    return levels_map[country_code];
}

poseidon::Graphid poseidon::Hierarchy::GetGraphId(const poseidon::WGS84Point& point, int level) {
    Graphid graphid;
    if (level < levels.size()) {
        auto tile_id = levels[level].tiles.tile_id(point);
        if (tile_id > 0) {
            graphid = {level, static_cast<uint32_t>(tile_id), 0};
        }
    }
    return graphid;
}