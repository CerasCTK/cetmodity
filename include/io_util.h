#ifndef CETMODITY_IO_UTIL_H
#define CETMODITY_IO_UTIL_H

void input_without_showing_char(char *dest, unsigned short dest_size);

/**
 * @brief Function to input a string from the user
 *
 * @param dest destination to store the input string
 * @param dest_size size of the destination buffer (include null character)
 */
void input_string(char *dest, unsigned short dest_size);

/**
 * @brief Function to print a message to the bottom left of the screen
 *
 * @param message Message to be printed
 */
void print_message_bottom_left(const char *message);

/**
 * @brief Function to wait for the user to press enter
 */
void wait_for_enter();

#endif // !CETMODITY_IO_UTIL_H
