// 测试 GeoPoint
#include <iostream>
#include "geo_point.h"
#include "envelop.h"

using namespace poseidon;

int main(int argc, char* argv[]) {
    GeoPoint<double> p1(1.0, 2.0);
    std::cout<<"p1: "<<p1.lng()<<", "<<p1.lat()<<std::endl;
    GeoPoint<double> p2;
    std::cout<<"p2: "<<p2.lng()<<", "<<p2.lat()<<std::endl;
    GeoPoint<double> p3(p1);
    std::cout<<"p3: "<<p3.lng()<<", "<<p3.lat()<<std::endl;

    Envelop<GeoPoint<double>> e1(p1, p2);
    std::cout<<"e1: "<<e1.min_x()<<", "<<e1.min_y()<<", "<<e1.max_x()<<", "<<e1.max_y()<<std::endl;


    return 0;
}
