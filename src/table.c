#include "table.h"

#include <stdio.h>
#include <uuid/uuid.h>

#include "string_converter.h"

#define PRINT_BORDER_X(border_len)                                             \
    (printf("%.*s\n", border_len, TABLE_BORDER_X))

void show_order_table(const dllist_order list_order) {
    // | INDEX | ID | SENDER | RECEIVER | LIST ITEM |
    const int QUANTITY_ITEMS = 5;
    const int NUM_OF_SEPARATE_CHAR = 6;
    const int INDEX_LEN = 3;
    const int border_x = INDEX_LEN + UUID_STR_LEN + SENDER_MAX_NAME_LEN
                         + RECEIVER_MAX_NAME_LEN + PRODUCT_MAX_NAME_LEN
                         + NUM_OF_SEPARATE_CHAR + QUANTITY_ITEMS;

    PRINT_BORDER_X(border_x);
    printf("|%*s|", INDEX_LEN, "IND");
    printf("%*s|", UUID_STR_LEN, "ID");
    printf("%*s|", SENDER_MAX_NAME_LEN, "SENDER");
    printf("%*s|", RECEIVER_MAX_NAME_LEN, "RECEIVER");
    printf("%*s|\n", PRODUCT_MAX_NAME_LEN + QUANTITY_ITEMS, "LIST ITEM");

    for (int i = 0; i < do_size(list_order); i++) {
        PRINT_BORDER_X(border_x);
        const order_node *n_order = do_get_by_index(list_order, i);

        if (n_order == NULL)
            continue;

        order order = n_order->order;
        const dllist_item item_list = order.items;
        const int item_list_size = di_size(item_list);
        char **item_info_array = list_item_to_strings(item_list);

        // Print first row
        printf("|%*d|", INDEX_LEN, i + 1);
        printf("%*s|", UUID_STR_LEN, order.id);
        printf("%*s|", SENDER_MAX_NAME_LEN, order.sender.name);
        printf("%*s|", RECEIVER_MAX_NAME_LEN, order.receiver.name);
        printf(
            "%*s|\n", PRODUCT_MAX_NAME_LEN + QUANTITY_ITEMS, item_info_array[0]
        );

        for (int j = 1; j < item_list_size; j++) {
            printf("|%*s|", INDEX_LEN, "");
            printf("%*s|", UUID_STR_LEN, "");
            printf("%*s|", SENDER_MAX_NAME_LEN, "");
            printf("%*s|", RECEIVER_MAX_NAME_LEN, "");
            printf(
                "%*s|\n", PRODUCT_MAX_NAME_LEN + QUANTITY_ITEMS,
                item_info_array[j]
            );
        }

        free_list_item_strings(item_info_array, item_list_size);
    }

    PRINT_BORDER_X(border_x);
}
