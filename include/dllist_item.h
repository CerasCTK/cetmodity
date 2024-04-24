#ifndef CETMODITY_LLIST_ITEM_H
#define CETMODITY_LLIST_ITEM_H

#include "item.h"

struct _item_node {
    item item;
    struct _item_node *next, *prev;
};
typedef struct _item_node item_node;

struct _dllist_item {
    item_node *head;
    item_node *tail;
};
typedef struct _dllist_item dllist_item;

#endif // !CETMODITY_LLIST_ITEM_H
