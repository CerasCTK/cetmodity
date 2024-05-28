#include "order.h"

#include "dllist_item.h"
#include "uuid_util.h"

#include <string.h>

bool is_same_order(const order o1, const order o2) {
    return strcmp(o1.id, o2.id) == 0;
}

order create_empty_order(const sender sender, const receiver receiver) {
    order new_order = { .sender = sender,
                        .receiver = receiver,
                        .items_price = 0,
                        .shipping_fee = 0,
                        .status = in_storage };

    uuid(new_order.id);

    di_init(&new_order.items);

    return new_order;
}

void order_add_item(order *order, const item new_item) {
    di_insert_end(&order->items, new_item);

    order->items_price = di_calculate_total_price(order->items);
    order->shipping_fee = order->items_price * SHIP_TAX;
}
