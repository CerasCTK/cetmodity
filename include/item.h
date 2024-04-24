#ifndef CETMODITY_ITEM_H
#define CETMODITY_ITEM_H

#include "define.h"

struct _item {
    char product_name[PRODUCT_MAX_NAME_LEN];
    unsigned int quantity;
    unsigned long unit_price;
};
typedef struct _item item;

#endif // !CETMODITY_ITEM_H
