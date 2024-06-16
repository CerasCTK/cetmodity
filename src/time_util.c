#include "time_util.h"
#include <time.h>

void get_time_string(char dist[TIME_STRING_LEN]) {
    time_t rawtime;
    time(&rawtime);

    struct tm *time_info;
    time_info = localtime(&rawtime);

    strftime(dist, TIME_STRING_LEN, "%Y-%m-%d %H:%M:%S", time_info);
}
