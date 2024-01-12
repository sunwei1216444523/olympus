#include <iostream>
#include "geotools.h"

int main() {
    auto ret = venus::UTM2WGS84(510500, 7042500, 32);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}