#ifndef CETMODITY_LLIST_ITEM_H
#define CETMODITY_LLIST_ITEM_H

#include "item.h"
#include "bool.h"

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

void di_init(dllist_item *);

bool di_is_empty(dllist_item);

bool di_is_in_list(dllist_item, item);

int di_size(dllist_item);

void di_insert_begin(dllist_item *, item);

void di_insert_after(dllist_item *, item_node *, item);

void di_insert_before(dllist_item *, item_node *, item);

#endif // !CETMODITY_LLIST_ITEM_H