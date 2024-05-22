#ifndef CETMODITY_ITEM_H
#define CETMODITY_ITEM_H

#include "bool.h"

#define PRODUCT_MAX_NAME_LEN 15

typedef struct item {
    char product_name[PRODUCT_MAX_NAME_LEN + 1];
    unsigned int quantity;
    unsigned long unit_price;
} item;

bool is_same_item(item i1, item i2);

item create_item(
    const char* product_name, unsigned int quantity,
    unsigned long unit_price
);

int get_item_info_len(item item);

char *get_item_info_string(item item);

#endif // !CETMODITY_ITEM_H
