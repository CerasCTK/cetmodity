#include "table.h"

#include "dllist_deliver.h"
#include "item.h"
#include "receiver.h"
#include "sender.h"
#include "string_converter.h"
#include "uuid_util.h"

#include <iso646.h>
#include <stdio.h>
#include <string.h>

#define INDEX_COL_WIDTH 3
#define LOCATED_COL_WIDTH 22

#define PRINT_BORDER_X(border_width)                                           \
    (printf("%.*s\n", border_width, TABLE_BORDER_X))

void show_order_table_for_manager(
    const dllist_order *const list_order,
    const dllist_deliver *const list_deliver
) {
    // | INDEX | ID | SENDER | RECEIVER | PHONE | LOCATED | LIST ITEM | STATUS |
    if (do_is_empty(list_order)) {
        printf("Order list is empty, no order found!\n");
        SEPERATE_LINE;
        return;
    }

    const int QUANTITY_ITEMS = 5;
    const int NUM_OF_SEPERATE = 9;
    const int border_width
        = INDEX_COL_WIDTH + ID_LEN + SENDER_MAX_NAME_LEN + RECEIVER_MAX_NAME_LEN
          + RECEIVER_MAX_PHONE_LEN + LOCATED_COL_WIDTH + PRODUCT_MAX_NAME_LEN
          + NUM_OF_SEPERATE + QUANTITY_ITEMS + ORDER_STATUS_LENGTH;

    PRINT_BORDER_X(border_width);
    printf("|%*s|", INDEX_COL_WIDTH, "IND");
    printf("%*s|", ID_LEN, "ID");
    printf("%*s|", SENDER_MAX_NAME_LEN, "Sender");
    printf("%*s|", RECEIVER_MAX_NAME_LEN, "Receiver");
    printf("%*s|", RECEIVER_MAX_PHONE_LEN, "Phone");
    printf("%*s|", LOCATED_COL_WIDTH, "Located");
    printf("%*s|", PRODUCT_MAX_NAME_LEN + QUANTITY_ITEMS, "List items");
    printf("%*s|\n", ORDER_STATUS_LENGTH, "Status");

    for (int i = 0; i < do_size(list_order); i++) {
        PRINT_BORDER_X(border_width);

        const order_node *n_order = do_get_by_index(list_order, i);

        if (n_order == NULL)
            continue;

        order *order = n_order->order;

        // Print first row
        printf("|%*d|", INDEX_COL_WIDTH, i + 1);
        printf("%*s|", ID_LEN, order->id);
        printf("%*s|", SENDER_MAX_NAME_LEN, order->sender.name);
        printf("%*s|", RECEIVER_MAX_NAME_LEN, order->receiver.name);
        printf("%*s|", RECEIVER_MAX_PHONE_LEN, order->receiver.phone_number);
        printf(
            "%*.2lf, ", LOCATED_COL_WIDTH / 2 - 1,
            order->receiver.location.latitude
        );
        printf(
            "%*.2lf|", LOCATED_COL_WIDTH / 2 - 1,
            order->receiver.location.longitude
        );

        const dllist_item *item_list = order->item_list;

        const int item_list_size = di_size(item_list);
        if (item_list_size == 0) {
            printf("%*s|\n", PRODUCT_MAX_NAME_LEN + QUANTITY_ITEMS, "");
            continue;
        }

        char **item_info_array = list_item_to_strings(item_list);
        char status[ORDER_STATUS_LENGTH];

        if (order->status == 0) {
            strcpy(status, "In storage");
        } else if (order->status == 1) {
            char deliver[DELIVER_MAX_NAME_LEN];

            strcpy(
                deliver, dd_search_node_by_id(list_deliver, order->deliver_id)
                             ->deliver->name
            );
            strcpy(status, "In transit - ");
            strcat(status, deliver);
        } else {
            strcpy(status, "Delived");
        }

        printf(
            "%*s|", PRODUCT_MAX_NAME_LEN + QUANTITY_ITEMS, item_info_array[0]
        );
        printf("%*s|\n", ORDER_STATUS_LENGTH, status);
        for (int j = 1; j < item_list_size; j++) {
            printf("|%*s|", INDEX_COL_WIDTH, "");
            printf("%*s|", ID_LEN, "");
            printf("%*s|", SENDER_MAX_NAME_LEN, "");
            printf("%*s|", RECEIVER_MAX_NAME_LEN, "");
            printf("%*s|", RECEIVER_MAX_PHONE_LEN, "");
            printf("%*s|", LOCATED_COL_WIDTH, "");
            printf(
                "%*s|", PRODUCT_MAX_NAME_LEN + QUANTITY_ITEMS,
                item_info_array[j]
            );
            printf("%*s|\n", ORDER_STATUS_LENGTH, "");
        }

        free_list_item_strings(item_info_array, item_list_size);
    }

    PRINT_BORDER_X(border_width);
}

void show_order_table_for_deliver(const deliver *const deliver) {
    printf("ID: %s\n", deliver->id);
    printf("Name: %s\n", deliver->name);
    printf("Phone number: %s\n", deliver->phone_number);

    // | INDEX | ID | SENDER | RECEIVER | LOCATED | COUNT_PRICE | STATUS |
    const int COUNT_ITEMS_PRICE_WIDTH = 9;
    const int NUM_OF_SEPERATE = 8;
    int border_width = INDEX_COL_WIDTH + ID_LEN + SENDER_MAX_NAME_LEN
                       + RECEIVER_MAX_NAME_LEN + LOCATED_COL_WIDTH
                       + COUNT_ITEMS_PRICE_WIDTH + ORDER_STATUS_LENGTH
                       + NUM_OF_SEPERATE;

    PRINT_BORDER_X(border_width);
    printf("|%*s|", INDEX_COL_WIDTH, "IND");
    printf("%*s|", ID_LEN, "ID");
    printf("%*s|", SENDER_MAX_NAME_LEN, "SENDER");
    printf("%*s|", RECEIVER_MAX_NAME_LEN, "RECEIVER");
    printf("%*s|", LOCATED_COL_WIDTH, "LOCATED");
    printf("%*s|", COUNT_ITEMS_PRICE_WIDTH, "COUNT");
    printf("%*s|\n", ORDER_STATUS_LENGTH, "STATUS");

    for (int i = 0; i < do_size(deliver->orders); i++) {
        PRINT_BORDER_X(border_width);

        order_node *node = do_get_by_index(deliver->orders, i);

        char status[ORDER_STATUS_LENGTH];

        if (node->order->status == 0) {
            strcpy(status, "In storage");
        } else if (node->order->status == 1) {
            strcpy(status, "In transit");
        } else {
            strcpy(status, "Delived");
        }

        printf("|%*d|", INDEX_COL_WIDTH, i + 1);
        printf("%*s|", ID_LEN, node->order->id);
        printf("%*s|", SENDER_MAX_NAME_LEN, node->order->sender.name);
        printf("%*s|", RECEIVER_MAX_NAME_LEN, node->order->receiver.name);
        printf(
            "%*.2lf, ", LOCATED_COL_WIDTH / 2 - 1,
            node->order->receiver.location.latitude
        );
        printf(
            "%*.2lf|", LOCATED_COL_WIDTH / 2 - 1,
            node->order->receiver.location.longitude
        );
        printf(
            "%*lu|", COUNT_ITEMS_PRICE_WIDTH,
            node->order->items_price + node->order->shipping_fee
        );
        printf("%*s|\n", ORDER_STATUS_LENGTH, status);
    }

    PRINT_BORDER_X(border_width);
}

void show_order_invoice_table(const order *const order) {
    printf("\t%-20s", "Sender");
    printf("Name: %s\n", order->sender.name);
    printf("\t%-20s", "");
    printf("Phone: %s\n", order->sender.phone_number);
    printf("\t%-20s", "");
    printf(
        "Located: %.2f %.2f\n", order->sender.location.longitude,
        order->sender.location.latitude
    );

    printf("\t%-20s", "Receiver");
    printf("Name: %s\n", order->receiver.name);
    printf("\t%-20s", "");
    printf("Phone: %s\n", order->receiver.phone_number);
    printf("\t%-20s", "");
    printf(
        "Located: %.2f %.2f\n", order->receiver.location.longitude,
        order->receiver.location.latitude
    );

    printf("\n\t%-20s", "List item");

    const dllist_item *item_list = order->item_list;

    const int item_list_size = di_size(item_list);
    if (item_list_size == 0) {
        printf("");
    }

    char **item_info_array = list_item_to_strings(item_list);
    printf("1. %s\n", item_info_array[0]);

    for (int i = 1; i < item_list_size; i++) {
        printf("\t%-20s", "");
        printf("%d. %s\n", i + 1, item_info_array[i]);
    }

    printf("\n\t%-20s", "Price: ");
    printf("%lu\n", order->items_price);
    printf("\t%-20s", "Ship: ");
    printf("%u\n", order->shipping_fee);
    printf("\t%-20s", "Total price: ");
    printf("%lu\n", order->shipping_fee + order->items_price);
}

void show_deliver_table(const dllist_deliver *const list_deliver) {
    if (dd_is_empty(list_deliver)) {
        printf("Deliver list is empty, no deliver found!\n");
        SEPERATE_LINE;

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

        deliver *deliver = dd_get_by_index(list_deliver, i)->deliver;
        int num_of_orders = do_size(deliver->orders);

        printf("|%*d|", INDEX_COL_WIDTH, i + 1);
        printf("%*s|", ID_LEN, deliver->id);
        printf("%*s|", DELIVER_MAX_NAME_LEN, deliver->name);
        printf("%*s|", DELIVER_MAX_PHONE_LEN, deliver->phone_number);
        printf("%*s|", USERNAME_MAX_LEN, deliver->account.username);
        printf("%*d|\n", NUM_OF_ORDER_LEN, num_of_orders);
    }

    PRINT_BORDER_X(border_x);
}
