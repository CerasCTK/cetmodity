#ifndef CETMODITY_COORDINATE_H
#define CETMODITY_COORDINATE_H

#include <math.h>

#define EARTH_RADIUS 6371;
#define EARTH_PERIMETER (2 * EARTH_RADIUS * M_PI)

typedef struct coordinate {
    double latitude;
    double longitude;
} coordinate;

float degrees_to_radians(double degrees);

double calculate_distance(coordinate c1, coordinate c2);

#endif // !CETMODITY_COORDINATE_H
