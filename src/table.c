#include "table.h"

#include <stdio.h>
#include <uuid/uuid.h>

#include "item.h"
#include "receiver.h"
#include "sender.h"
#include "string_converter.h"

#define INDEX_COL_WIDTH 3

#define PRINT_BORDER_X(border_width)                                           \
    (printf("%.*s\n", border_width, TABLE_BORDER_X))

void show_order_table(const dllist_order list_order) {
    // | INDEX | ID | SENDER | RECEIVER | LIST ITEM |
    if (do_is_empty(list_order)) {
        printf("No order found\n");
        return;
    }

    const int QUANTITY_ITEMS = 5;
    const int NUM_OF_SEPERATE = 6;
    const int border_width = INDEX_COL_WIDTH + UUID_STR_LEN
                             + SENDER_MAX_NAME_LEN + RECEIVER_MAX_NAME_LEN
                             + PRODUCT_MAX_NAME_LEN + NUM_OF_SEPERATE
                             + QUANTITY_ITEMS;

    PRINT_BORDER_X(border_width);
    printf("|%*s|", INDEX_COL_WIDTH, "IND");
    printf("%*s|", UUID_STR_LEN, "ID");
    printf("%*s|", SENDER_MAX_NAME_LEN, "SENDER");
    printf("%*s|", RECEIVER_MAX_NAME_LEN, "RECEIVER");
    printf("%*s|\n", PRODUCT_MAX_NAME_LEN + QUANTITY_ITEMS, "LIST ITEM");

    for (int i = 0; i < do_size(list_order); i++) {
        PRINT_BORDER_X(border_width);

        const order_node *n_order = do_get_by_index(list_order, i);

        if (n_order == NULL)
            continue;

        order order = n_order->order;

        // Print first row
        printf("|%*d|", INDEX_COL_WIDTH, i + 1);
        printf("%*s|", UUID_STR_LEN, order.id);
        printf("%*s|", SENDER_MAX_NAME_LEN, order.sender.name);
        printf("%*s|", RECEIVER_MAX_NAME_LEN, order.receiver.name);

        const dllist_item item_list = order.items;

        const int item_list_size = di_size(item_list);
        if (item_list_size == 0) {
            printf("%*s|\n", PRODUCT_MAX_NAME_LEN + QUANTITY_ITEMS, "");
            continue;
        }

        char **item_info_array = list_item_to_strings(item_list);

        printf(
            "%*s|\n", PRODUCT_MAX_NAME_LEN + QUANTITY_ITEMS, item_info_array[0]
        );
        for (int j = 1; j < item_list_size; j++) {
            printf("|%*s|", INDEX_COL_WIDTH, "");
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

    PRINT_BORDER_X(border_width);
}

void show_deliver_table(const dllist_deliver list_deliver) {
    // | INDEX | ID | NAME | PHONE NUMBER | ACCOUNT | NUM OF ORDER |
    const int NUM_OF_SEPARATE_CHAR = 7;
    const int NUM_OF_ORDER_LEN = 5;
    const int border_x = INDEX_COL_WIDTH + UUID_STR_LEN + DELIVER_MAX_NAME_LEN + DELIVER_MAX_PHONE_LEN + USERNAME_MAX_LEN + NUM_OF_ORDER_LEN + NUM_OF_SEPARATE_CHAR;

    PRINT_BORDER_X(border_x);
    printf("|%*s|", INDEX_COL_WIDTH, "IND");
    printf("%*s|", UUID_STR_LEN, "ID");
    printf("%*s|", DELIVER_MAX_NAME_LEN, "DELIVER");
    printf("%*s|", DELIVER_MAX_PHONE_LEN, "PHONE");
    printf("%*s|", USERNAME_MAX_LEN, "ACCOUNT");
    printf("%*s|\n", NUM_OF_ORDER_LEN, "ORDER");

    for (int i = 0; i < dd_size(list_deliver); i++) {
        PRINT_BORDER_X(border_x);

        deliver deliver = dd_get_by_index(list_deliver, i)->deliver;
        int count_orders = do_size(deliver.orders);

        printf("|%*d|", INDEX_COL_WIDTH, i + 1);
        printf("%*s|", UUID_STR_LEN, deliver.id);
        printf("%*s|", DELIVER_MAX_NAME_LEN, deliver.name);
        printf("%*s|", DELIVER_MAX_PHONE_LEN, deliver.phone_number);
        printf("%*s|", USERNAME_MAX_LEN, deliver.account.username);
        printf("%*d|\n", NUM_OF_ORDER_LEN, count_orders);
    }

    PRINT_BORDER_X(border_x);
}
