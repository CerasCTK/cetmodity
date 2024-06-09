#ifndef CETMODITY_ITEM_H
#define CETMODITY_ITEM_H

#include "bool.h"

#define PRODUCT_MAX_NAME_LEN 16

typedef struct item {
    char product_name[PRODUCT_MAX_NAME_LEN];
    unsigned int quantity;
    unsigned long unit_price;
} item;

bool is_same_item(const item *const i1, const item *const i2);

item *create_item(
    const char *product_name, const unsigned int quantity,
    const unsigned long unit_price
);

item *create_item_input();

const int get_item_info_len(const item *const item);

const char *get_item_info_string(const item *const item);

#endif // !CETMODITY_ITEM_H
