#ifndef CETMODITY_UUID_UTIL_H
#define CETMODITY_UUID_UTIL_H

#define ID_LEN 12 // Format: xxxxx-xxxxx\0

/**
 * @brief Create random uuid and save to dest
 *
 * @param dest Destination to store the uuid
 */
void uuid(char dest[ID_LEN]);

#endif // !CETMODITY_UUID_UTIL_H
