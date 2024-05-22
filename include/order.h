#ifndef CETMODITY_ORDER_H
#define CETMODITY_ORDER_H

#include <uuid/uuid.h>

#include "bool.h"
#include "dllist_item.h"
#include "receiver.h"
#include "sender.h"

#define SHIP_TAX 0.05

typedef enum order_status { IN_TRANSIT, DELIVERED } order_status;

typedef struct order {
    char id[UUID_STR_LEN];
    sender sender;
    receiver receiver;
    dllist_item items;
    unsigned long items_price;
    unsigned int shipping_fee;
} order;

bool is_same_order(const order o1, const order o2);

order create_empty_order(const sender sender, const receiver receiver);

void order_add_item(order *const order, const item new_item);

#endif // !CETMODITY_ORDER_H
