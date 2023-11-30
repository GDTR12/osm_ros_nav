#include "osm/osm_parser.hpp"

namespace osm_nav{

const double ANGLE2DEG = 0.017453293;
const double DEG2ANGLE = 57.295779513;
const int EARTH_RADIUS = 6371393;

Enu_t gnss2enu(double lon,double lat, double alt)
{
    Enu_t enu;
    enu.x = lon * ANGLE2DEG * EARTH_RADIUS;
    enu.y = lat * ANGLE2DEG * EARTH_RADIUS;
    enu.z = alt;
    return enu;
}


}

