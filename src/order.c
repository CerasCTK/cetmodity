#include "order.h"

#include "dllist_item.h"
#include "time_util.h"
#include "uuid_util.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <table.h>

const bool is_same_order(const order *const o1, const order *const o2) {
    return strcmp(o1->id, o2->id) == 0;
}

order *const create_empty_order(const sender sender, const receiver receiver) {
    order *new_order = malloc(sizeof(order));

    uuid(new_order->id);

    strcpy(new_order->deliver_id, "");

    new_order->sender = sender;
    new_order->receiver = receiver;

    di_init(&new_order->item_list);

    new_order->items_price = 0;
    new_order->shipping_fee = 0;

    new_order->status = in_storage;

    get_current_time(new_order->created_at);
    strcpy(new_order->delivered_at, "");

    return new_order;
}

order *const create_empty_order_full_info(
    const char *const id, const sender sender, const receiver receiver,
    const char *const created_at, const char *const delivered_at
) {
    order *new_order = malloc(sizeof(order));

    strcpy(new_order->id, id);
    strcpy(new_order->deliver_id, "");

    new_order->sender = sender;
    new_order->receiver = receiver;

    di_init(&new_order->item_list);

    new_order->items_price = 0;
    new_order->shipping_fee = 0;

    new_order->status = in_storage;

    strcpy(new_order->created_at, created_at);
    strcpy(new_order->delivered_at, delivered_at);

    return new_order;
}

void order_add_item(order *const order, item *const new_item) {
    di_insert(order->item_list, new_item);

    // Update price
    order->items_price = di_calculate_total_price(order->item_list);
    order->shipping_fee = order->items_price * SHIP_TAX;
}

void order_add_item_input(order *const order) {
    item *new_item = create_item_input();

    order_add_item(order, new_item);
}

void show_order_information(const order *const order) {
    char status[ORDER_STATUS_LENGTH];

    if (order->status == 0) {
        strcpy(status, "In storage");
    } else if (order->status == 1) {
        strcpy(status, "In transit");
    } else {
        strcpy(status, "Delived");
    }

    printf("\t%-20s", "Order's status");
    printf("%s\n", status);

    show_order_invoice_table(order);
}
