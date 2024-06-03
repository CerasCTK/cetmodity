#include "table.h"

#include "dllist_deliver.h"
#include "item.h"
#include "receiver.h"
#include "sender.h"
#include "string_converter.h"
#include "uuid_util.h"

#include <stdio.h>
#include <string.h>

#define INDEX_COL_WIDTH 3

#define PRINT_BORDER_X(border_width)                                           \
    (printf("%.*s\n", border_width, TABLE_BORDER_X))

void show_order_table_for_manager(const dllist_order list_order) {
    // | INDEX | ID | SENDER | RECEIVER | PHONE | LOCATED | LIST ITEM |
    if (do_is_empty(list_order)) {
        printf("No order found!\n");
        printf("---------------------------------\n");
        return;
    }

    const int QUANTITY_ITEMS = 5;
    const int NUM_OF_SEPERATE = 8;
    const int LOCATED_COL_WIDTH = 10 * 2 + 2;
    const int border_width = INDEX_COL_WIDTH + ID_LEN + SENDER_MAX_NAME_LEN
                             + RECEIVER_MAX_NAME_LEN + RECEIVER_MAX_PHONE_LEN
                             + LOCATED_COL_WIDTH + PRODUCT_MAX_NAME_LEN
                             + NUM_OF_SEPERATE + QUANTITY_ITEMS;

    PRINT_BORDER_X(border_width);
    printf("|%*s|", INDEX_COL_WIDTH, "IND");
    printf("%*s|", ID_LEN, "ID");
    printf("%*s|", SENDER_MAX_NAME_LEN, "Sender");
    printf("%*s|", RECEIVER_MAX_NAME_LEN, "Receiver");
    printf("%*s|", RECEIVER_MAX_PHONE_LEN, "Phone");
    printf("%*s|", LOCATED_COL_WIDTH, "Located");
    printf("%*s|\n", PRODUCT_MAX_NAME_LEN + QUANTITY_ITEMS, "List items");

    for (int i = 0; i < do_size(list_order); i++) {
        PRINT_BORDER_X(border_width);

        const order_node *n_order = do_get_by_index(list_order, i);

        if (n_order == NULL)
            continue;

        order order = n_order->order;

        // Print first row
        printf("|%*d|", INDEX_COL_WIDTH, i + 1);
        printf("%*s|", ID_LEN, order.id);
        printf("%*s|", SENDER_MAX_NAME_LEN, order.sender.name);
        printf("%*s|", RECEIVER_MAX_NAME_LEN, order.receiver.name);
        printf("%*s|", RECEIVER_MAX_PHONE_LEN, order.receiver.phone_number);
        printf(
            "%*.3lf, ", LOCATED_COL_WIDTH / 2 - 1,
            order.receiver.location.latitude
        );
        printf(
            "%*.3lf|", LOCATED_COL_WIDTH / 2 - 1,
            order.receiver.location.longitude
        );

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
            printf("%*s|", ID_LEN, "");
            printf("%*s|", SENDER_MAX_NAME_LEN, "");
            printf("%*s|", RECEIVER_MAX_NAME_LEN, "");
            printf("%*s|", RECEIVER_MAX_PHONE_LEN, "");
            printf("%*s|", LOCATED_COL_WIDTH, "");
            printf(
                "%*s|\n", PRODUCT_MAX_NAME_LEN + QUANTITY_ITEMS,
                item_info_array[j]
            );
        }

        free_list_item_strings(item_info_array, item_list_size);
    }

    PRINT_BORDER_X(border_width);
}

void show_order_table_for_deliver(deliver deliver) {
    printf("ID: %s\n", deliver.id);
    printf("Name: %s\n", deliver.name);
    printf("Phone number: %s\n", deliver.phone_number);

    // | INDEX | ID | SENDER | RECEIVER | LOCATED | COUNT_PRICE | STATUS |
    const int COUNT_ITEMS_PRICE_WIDTH = 9;
    const int LOCATED_COL_WIDTH = 10 * 2 + 2;
    const int ORDER_STATUS_COL_WIDTH = 12;
    const int NUM_OF_SEPERATE = 8;
    int border_width = INDEX_COL_WIDTH + ID_LEN + SENDER_MAX_NAME_LEN
                       + RECEIVER_MAX_NAME_LEN + LOCATED_COL_WIDTH
                       + COUNT_ITEMS_PRICE_WIDTH + ORDER_STATUS_COL_WIDTH
                       + NUM_OF_SEPERATE;

    PRINT_BORDER_X(border_width);
    printf("|%*s|", INDEX_COL_WIDTH, "IND");
    printf("%*s|", ID_LEN, "ID");
    printf("%*s|", SENDER_MAX_NAME_LEN, "SENDER");
    printf("%*s|", RECEIVER_MAX_NAME_LEN, "RECEIVER");
    printf("%*s|", LOCATED_COL_WIDTH, "LOCATED");
    printf("%*s|", COUNT_ITEMS_PRICE_WIDTH, "COUNT");
    printf("%*s|\n", ORDER_STATUS_COL_WIDTH, "STATUS");

    for (int i = 0; i < do_size(deliver.orders); i++) {
        PRINT_BORDER_X(border_width);

        order_node *node = do_get_by_index(deliver.orders, i);

        char status[ORDER_STATUS_COL_WIDTH];

        if (node->order.status == 0) {
            strcpy(status, "In storage");
        } else if (node->order.status == 1) {
            strcpy(status, "In transit");
        } else {
            strcpy(status, "Delived");
        }

        printf("|%*d|", INDEX_COL_WIDTH, i + 1);
        printf("%*s|", ID_LEN, node->order.id);
        printf("%*s|", SENDER_MAX_NAME_LEN, node->order.sender.name);
        printf("%*s|", RECEIVER_MAX_NAME_LEN, node->order.receiver.name);
        printf(
            "%*.3lf, ", LOCATED_COL_WIDTH / 2 - 1,
            node->order.receiver.location.latitude
        );
        printf(
            "%*.3lf|", LOCATED_COL_WIDTH / 2 - 1,
            node->order.receiver.location.longitude
        );
        printf(
            "%*lu|", COUNT_ITEMS_PRICE_WIDTH,
            node->order.items_price + node->order.shipping_fee
        );
        printf("%*s|\n", ORDER_STATUS_COL_WIDTH, status);
    }

    PRINT_BORDER_X(border_width);
}

void show_order_detail(order order) {
    int border_width = 35;

    PRINT_BORDER_X(border_width);

    printf("Sender's name: %s\n", order.sender.name);
    printf(
        "Sender's location: %.2lf, %.2lf\n", order.sender.location.latitude,
        order.sender.location.longitude
    );
    printf("Phone number: %s\n", order.sender.phone_number);

    PRINT_BORDER_X(border_width);

    printf("Receiver's name: %s\n", order.receiver.name);
    printf(
        "Receiver's location: %.2lf, %.2lf\n", order.receiver.location.latitude,
        order.receiver.location.longitude
    );
    printf("Phone number: %s\n", order.receiver.phone_number);

    PRINT_BORDER_X(border_width);

    printf("List items: \n");

    for (int i = 0; i < di_size(order.items); i++) {
        item_node *item_node = di_get_by_index(order.items, i);

        printf(
            "%d. %s - %u\n", i + 1, item_node->item.product_name,
            item_node->item.quantity
        );
    }

    PRINT_BORDER_X(border_width);
    printf("Total order price: %lu\n", order.items_price + order.shipping_fee);

    PRINT_BORDER_X(border_width);
}

void show_deliver_table(const dllist_deliver list_deliver) {
    if (dd_is_empty(list_deliver)) {
        printf("No deliver found!\n");
        printf("------------------------------------\n");
        return;
    }

    // | INDEX | ID | NAME | PHONE NUMBER | ACCOUNT | NUM OF ORDER |
    const int NUM_OF_SEPARATE_CHAR = 7;
    const int NUM_OF_ORDER_LEN = 5;
    const int border_x = INDEX_COL_WIDTH + ID_LEN + DELIVER_MAX_NAME_LEN
                         + DELIVER_MAX_PHONE_LEN + USERNAME_MAX_LEN
                         + NUM_OF_ORDER_LEN + NUM_OF_SEPARATE_CHAR;

    PRINT_BORDER_X(border_x);
    printf("|%*s|", INDEX_COL_WIDTH, "IND");
    printf("%*s|", ID_LEN, "ID");
    printf("%*s|", DELIVER_MAX_NAME_LEN, "Deliver");
    printf("%*s|", DELIVER_MAX_PHONE_LEN, "Phone");
    printf("%*s|", USERNAME_MAX_LEN, "Username");
    printf("%*s|\n", NUM_OF_ORDER_LEN, "Order");

    for (int i = 0; i < dd_size(list_deliver); i++) {
        PRINT_BORDER_X(border_x);

        deliver deliver = dd_get_by_index(list_deliver, i)->deliver;
        int count_orders = do_size(deliver.orders);

        printf("|%*d|", INDEX_COL_WIDTH, i + 1);
        printf("%*s|", ID_LEN, deliver.id);
        printf("%*s|", DELIVER_MAX_NAME_LEN, deliver.name);
        printf("%*s|", DELIVER_MAX_PHONE_LEN, deliver.phone_number);
        printf("%*s|", USERNAME_MAX_LEN, deliver.account.username);
        printf("%*d|\n", NUM_OF_ORDER_LEN, count_orders);
    }

    PRINT_BORDER_X(border_x);
}
