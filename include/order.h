#ifndef CETMODITY_ORDER_H
#define CETMODITY_ORDER_H

#include "bool.h"
#include "dllist_item.h"
#include "receiver.h"
#include "sender.h"
#include "uuid_util.h"

#define SHIP_TAX 0.05
#define ORDER_STATUS_LENGTH 31

typedef enum order_status { in_storage, in_transit, delivered } order_status;

typedef struct order {
    char id[ID_LEN];
    char deliver_id[ID_LEN];
    sender sender;
    receiver receiver;
    dllist_item items;
    unsigned long items_price;
    unsigned int shipping_fee;
    order_status status;
} order;

bool is_same_order(order o1, order o2);

order create_empty_order(sender sender, receiver receiver);

void order_add_item(order *order, item new_item);

void order_add_item_input(order *order);

void show_order_information(order order);

#endif // !CETMODITY_ORDER_H
