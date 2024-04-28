#ifndef CETMODITY_COORDINATE_H
#define CETMODITY_COORDINATE_H

#include <math.h>

#define EARTH_RADIUS 6371;
#define EARTH_PERIMETER (2 * EARTH_RADIUS * M_PI)

struct _coordinate {
    double latitude;
    double longitude;
};
typedef struct _coordinate coordinate;

float _degrees_to_radians(double);

double calculate_distance(coordinate, coordinate);

#endif // !CETMODITY_COORDINATE_H
