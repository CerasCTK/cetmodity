#ifndef CETMODITY_LLIST_ITEM_H
#define CETMODITY_LLIST_ITEM_H

#include "bool.h"
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

void di_init(dllist_item *);

bool di_is_empty(dllist_item);

bool di_is_in_list(dllist_item, item);

int di_size(dllist_item);

void di_insert_begin(dllist_item *, item);

void di_insert_end(dllist_item *, item);

void di_insert_after(dllist_item *, item_node *, item);

void di_insert_before(dllist_item *, item_node *, item);

item_node *di_get_by_index(dllist_item, int);

item_node *di_search_node_by_name(dllist_item, char *);

void di_delete(dllist_item *, item_node *);

void di_delete_begin(dllist_item *);

void di_delete_end(dllist_item *);

void di_delete_before(dllist_item *, item_node *);

void di_delete_after(dllist_item *, item_node *);

void di_free(dllist_item *);

#endif // !CETMODITY_LLIST_ITEM_H
