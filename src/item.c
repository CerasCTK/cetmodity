#include "item.h"

#include <string.h>

bool is_same_item(item first, item second) {
    return strcmp(first.product_name, second.product_name) == 0;
}

item create_item(
    const char *product_name, unsigned int quantity, unsigned long unit_price
) {
    item new_item = { .quantity = quantity, .unit_price = unit_price };
    strcpy(new_item.product_name, product_name);

    return new_item;
}
