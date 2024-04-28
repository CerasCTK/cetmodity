#include "coordinate.h"
#include <math.h>

float _degrees_to_radians(double degrees) { return degrees * M_PI / 180; }

double calculate_distance(coordinate first, coordinate second) {
    double distance_lat = _degrees_to_radians(first.latitude - second.latitude);
    double distance_lon
        = _degrees_to_radians(first.longitude - second.longitude);

    double first_lat_rad = _degrees_to_radians(first.latitude);
    double second_lat_rad = _degrees_to_radians(second.latitude);

    double a = pow(sin(distance_lat / 2), 2)
               + pow(sin(distance_lon / 2), 2) * cos(first_lat_rad)
                     * cos(second_lat_rad);
    double c = 2 * asin(sqrt(a));

    return c * EARTH_RADIUS;
}
