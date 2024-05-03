#include "order.h"
#include "dllist_item.h"

#include <string.h>

bool is_same_order(order first, order second) {
    return strcmp(first.id, second.id) == 0;
}

order create_empty_order(
    sender sender, receiver receiver, unsigned long items_price,
    unsigned int shipping_fee
) {
    order new_order = { .sender = sender,
                        .receiver = receiver,
                        .items_price = items_price,
                        .shipping_fee = shipping_fee };

    di_init(&new_order.items);

    return new_order;
}
