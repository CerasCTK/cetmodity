#include "string_converter.h"

#include <stdlib.h>
#include <string.h>

char **list_item_to_strings(const dllist_item *const list) {
    const int list_size = di_size(list);

    char **array = malloc(list_size * sizeof(char *));

    for (int i = 0; i < list_size; i++) {
        const item_node *n_item = di_get_by_index(list, i);

        if (n_item == NULL)
            continue;

        const item *item = n_item->item;
        array[i] = (char *)malloc(get_item_info_len(item) * sizeof(char));
        char *item_info = get_item_info_string(item);
        strcpy(array[i], item_info);
        free(item_info);
    }

    return array;
}

void free_list_item_strings(char **strings, const int size) {
    for (int i = 0; i < size; i++) {
        free(strings[i]);
    }
    free(strings);
}
