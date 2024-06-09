#ifndef CETMODITY_LLIST_ITEM_H
#define CETMODITY_LLIST_ITEM_H

#include "bool.h"
#include "item.h"

typedef struct item_node {
    item *item;
    struct item_node *next, *prev;
} item_node;

typedef struct dllist_item {
    item_node *head;
    item_node *tail;
} dllist_item;

void di_init(dllist_item *const list);

const bool di_is_empty(const dllist_item *const list);

const bool di_is_in_list(const dllist_item *const list, const item *const item);

const int di_size(const dllist_item *const list);

void di_insert_end(dllist_item *const list, item *const item);

item_node *const di_get_by_index(const dllist_item *const list, int index);

item_node *const di_search_node_by_product_name(
    const dllist_item *const list, const char *item_name
);

item_node *di_search_node_by_product_name_input(const dllist_item *const list);

void di_delete(dllist_item *const list, item_node *const node);

const unsigned long di_calculate_total_price(const dllist_item *const list);

void di_free(dllist_item *const list);

#endif // !CETMODITY_LLIST_ITEM_H
