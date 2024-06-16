#include "time_util.h"
#include <time.h>

void get_current_time(char dest[TIME_STRING_LEN]) {
    time_t rawtime;
    time(&rawtime);

    struct tm *time_info;
    time_info = localtime(&rawtime);

    strftime(dest, TIME_STRING_LEN, "%Y-%m-%d %H:%M:%S", time_info);
}
