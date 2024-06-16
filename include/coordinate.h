#ifndef CETMODITY_COORDINATE_H
#define CETMODITY_COORDINATE_H

#include <math.h>

#define EARTH_RADIUS 6371
#define EARTH_PERIMETER (2 * EARTH_RADIUS * M_PI)

typedef struct coordinate {
    double latitude;
    double longitude;
} coordinate;

/**
 * @brief Convert degrees to radians
 *
 * @param degrees Degrees to convert
 * @return Radian value after conversion
 */
const float degrees_to_radians(const double degrees);

/**
 * @brief Calculate distance between two coordinates
 *
 * @param c1 First coordinate
 * @param c2 Second coordinate
 * @return Distance between two coordinates
 */
const double calculate_distance(const coordinate c1, const coordinate c2);

#endif // !CETMODITY_COORDINATE_H
