#ifndef GEO_TOOLS_H
#define GEO_TOOLS_H

#include <pair>

namespace venus {
    static std::pair<double, double> UTM2WGS84(double x, double y, int zone);
}


#endif // GEO_TOOLS_H