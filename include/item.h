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

bool is_same_item(const item, const item);

item create_item(const char * const, const unsigned int, const unsigned long);

#endif // !CETMODITY_ITEM_H
