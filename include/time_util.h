#ifndef CETMODITY_TIME_UTIL_H
#define CETMODITY_TIME_UTIL_H

#define TIME_STRING_LEN 20 // Format: "YYYY-MM-DD HH:MM:SS"

/**
 * @brief Get current time and save to dist
 *
 * @param dist Distination to store the current time
 */
void get_current_time(char dest[TIME_STRING_LEN]);

#endif // !CETMODITY_TIME_UTIL_H
