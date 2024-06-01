#include "order.h"

#include "dllist_item.h"
#include "io_util.h"
#include "uuid_util.h"

#include <stdio.h>
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

void order_add_item_input(order *order) {
    char item_name[PRODUCT_MAX_NAME_LEN];
    unsigned int quantity;
    unsigned long unit_price;

    printf("Input the item name: ");
    input_string(item_name, PRODUCT_MAX_NAME_LEN);
    printf("Input the quantity: ");
    scanf("%u", &quantity);
    printf("Input the unit price: ");
    scanf("%lu", &unit_price);
    getchar();

    item new_item = create_item(item_name, quantity, unit_price);

    order_add_item(order, new_item);
}
