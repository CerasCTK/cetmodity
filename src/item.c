#include "item.h"

#include <string.h>

bool is_same_item(item i1, item i2) {
    return strcmp(i1.product_name, i2.product_name) == 0;
}

item create_item(
    const char *product_name, unsigned int quantity, unsigned long unit_price
) {
    item new_item = { .quantity = quantity, .unit_price = unit_price };
    strcpy(new_item.product_name, product_name);

    return new_item;
}
