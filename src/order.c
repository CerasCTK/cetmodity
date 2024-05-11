#include "order.h"
#include "dllist_item.h"
#include "uuid_util.h"

#include <string.h>

bool is_same_order(order first, order second) {
    return strcmp(first.id, second.id) == 0;
}

order create_empty_order(sender sender, receiver receiver) {
    order new_order = { .sender = sender,
                        .receiver = receiver,
                        .items_price = 0,
                        .shipping_fee = 0 };

    uuid(new_order.id);

    di_init(&new_order.items);

    return new_order;
}

void order_add_item(order *order, item new_item) {
    di_insert_end(&order->items, new_item);
}
