#ifndef POINT_PAIR_H
#define POINT_PAIR_H

namespace poseidon {
template <typename PrecisionT>
class PointPair : public std::pair<PrecisionT, PrecisionT> {
public:
    using std::pair<PrecisionT, PrecisionT>::pair;
    
    PrecisionT x() const {
        return this->first;
    }

    PrecisionT y() const {
        return this->second;
    }

    void set_x(PrecisionT x) {
        this->first = x;
    }

    void set_y(PrecisionT y) {
        this->second = y;
    }
    
};
}


#endif // POINT_PAIR_H