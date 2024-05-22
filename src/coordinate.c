#include "coordinate.h"
#include <math.h>

float degrees_to_radians(const double degrees) { return degrees * M_PI / 180; }

double calculate_distance(const coordinate c1, const coordinate c2) {
    const double distance_lat = degrees_to_radians(c1.latitude - c2.latitude);
    const double distance_lon = degrees_to_radians(c1.longitude - c2.longitude);

    const double first_lat_rad = degrees_to_radians(c1.latitude);
    const double second_lat_rad = degrees_to_radians(c2.latitude);

    const double a = pow(sin(distance_lat / 2), 2)
               + pow(sin(distance_lon / 2), 2) * cos(first_lat_rad)
                     * cos(second_lat_rad);
    const double c = 2 * asin(sqrt(a));

    return c * EARTH_RADIUS;
}
