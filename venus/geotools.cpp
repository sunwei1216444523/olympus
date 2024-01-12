#include <proj.h>
#include "geotools.h"

static std::pair<double, double> venus::UTM2WGS84(double x, double y, int zone) {
    std::string utm_epsg = "EPSG:" + std::to_string(32600 + zone);

    // 创建一个转换对象，从 UTM（zone）转换到 WGS84
    PJ* P = proj_create_crs_to_crs(PJ_DEFAULT_CTX, utm_epsg.c_str(), "EPSG:4326", NULL);
    PJ_COORD a, b;
    a = proj_coord(x, y, 0, 0);
    b = proj_trans(P, PJ_INV, a);

    std::cout << "UTM2WGS84: " << b.xyx.x << ", " << b.xyx.y << std::endl;
    return std::make_pair(b.xyx.x, b.xyx.y);
}
