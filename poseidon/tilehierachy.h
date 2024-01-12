#ifndef TILE_HIERACHY_H
#define TILE_HIERACHY_H

#include <vector>
#include "tiles.h"
#include "graphid.h"

/**
  *  主要完成层次结构的定义以及各项操作
  */
namespace poseidon {

struct TileLevel {
    int level;
    std::string name;
    poseidon::Tiles<WGS84Point> tiles;
};

/**
 * @brief 完成层次结构的定义。包括通过坐标获取GraphId等操作
*/
class TileHierachy {
public:
    static const std::vector<TileLevel>& levels(std::string country_code = "CHN");

    static Graphid GetGraphId(const WGS84Point& point, int level);
};

}


#endif // TILE_HIERACHY_H