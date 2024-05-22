#ifndef CETMODITY_STRING_CONVERTER_H
#define CETMODITY_STRING_CONVERTER_H

#include "dllist_item.h"

// Double linked-list item to string[]
char **list_item_to_strings(dllist_item list);

void free_list_item_strings(char **strings, int size);

#endif
