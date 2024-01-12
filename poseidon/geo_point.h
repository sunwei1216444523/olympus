#ifndef GEO_POINT_H
#define GEO_POINT_H

#include "point_pair.h"

namespace {
    // 经纬度本身也不会超过180度
    constexpr double INVALID_LL = 1000.0;
}

namespace poseidon {
template <typename PercisionT>
class GeoPoint : public PointPair<PercisionT> {
public:
    // 调用父类的构造函数   
    using PointPair<PercisionT>::PointPair;

    // 再给出构造函数
    GeoPoint()
        : PointPair<PercisionT>(INVALID_LL, INVALID_LL) {}

    GeoPoint(const PointPair<PercisionT>& p)
        : PointPair<PercisionT>(p) {}

    PercisionT lng() {
        return this->first;
    }

    PercisionT lat() {
        return this->second;
    }

    void set_lng(PercisionT lng) {
        this->first = lng;
    }

    void set_lat(PercisionT lat) {
        this->second = lat;
    }

    void reset() {
        this->first = INVALID_LL;
        this->second = INVALID_LL;
    }
};

using WGS84Point = GeoPoint<double>;
}


#endif // GEO_POINT_H