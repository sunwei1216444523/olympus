#include <cmath>
#include "tiles.h"


template <class coordinate_t>
poseidon::Tiles<coordinate_t>::Tiles(const Envelop<coordinate_t>& bound,
                       const float tile_size) {
    tile_size_ = tile_size;
    min_x_ = bound.min_x();
    min_y_ = bound.min_y();
    // 计算行列数
    nrows_ = static_cast<size_t>(std::ceil(bound.height() / tile_size));
    ncols_ = static_cast<size_t>(std::ceil(bound.width() / tile_size));
}