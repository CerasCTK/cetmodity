#ifndef CETMODITY_IO_UTIL_H
#define CETMODITY_IO_UTIL_H

void input_without_showing_char(char *dest, unsigned short dest_size);

/**
 * @brief Function to input a string from the user
 *
 * @param dest destination to store the input string
 * @param dest_size size of the destination buffer (not include null character)
 */
void input_string(char *dest, unsigned short dest_size);

void print_center(
    unsigned short msg_len, unsigned short lines, char messages[lines][msg_len]
);

#endif // !CETMODITY_IO_UTIL_H
