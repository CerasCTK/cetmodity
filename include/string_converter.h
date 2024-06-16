#ifndef CETMODITY_STRING_CONVERTER_H
#define CETMODITY_STRING_CONVERTER_H

#include "dllist_item.h"

// Double linked-list item to string[]
char **list_item_to_strings(const dllist_item *const list);

/**
 * @brief Free memory for list of strings
 *
 * @param strings List of strings
 * @param size Size of the list
 */
void free_list_item_strings(char **strings, int size);

#endif
