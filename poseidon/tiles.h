#ifndef TILES_H
#define TILES_H

#include <cstdint>
#include <iostream>
#include "envelop.h"

namespace poseidon {
    /**
    * 这里处理网格划分，Valhalla中是直接将整个世界划分，这里因为针对的是高精地图
    * 所以可以按照地区进行定制化划分，这样划分的粒度可以更细，划分的时候也需要注
    * 意均分的参数。
    */


template <class coordinate_t>
class Tiles {
public:
    Tiles(const Envelop<coordinate_t>& bound,
          const float tile_size);
    
    uint32_t tile_id(coordinate_t point) const {
        // 计算行列号
        uint32_t row = static_cast<uint32_t>((point.y() - min_y_) / tile_size_);
        uint32_t col = static_cast<uint32_t>((point.x() - min_x_) / tile_size_);
        // 计算tile id
        return row * ncols_ + col;
    }
private:
    size_t nrows_;
    size_t ncols_;

    double min_x_;
    double min_y_;
    size_t tile_size_;

};

}
#endif // TILES_H