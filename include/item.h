#ifndef CETMODITY_ITEM_H
#define CETMODITY_ITEM_H

#include "bool.h"
#include "define.h"

struct _item {
    char product_name[PRODUCT_MAX_NAME_LEN];
    unsigned int quantity;
    unsigned long unit_price;
};
typedef struct _item item;

bool is_same_item(const item i1, const item i2);

item create_item(
    const char *const product_name, const unsigned int quantity,
    const unsigned long unit_price
);

#endif // !CETMODITY_ITEM_H
