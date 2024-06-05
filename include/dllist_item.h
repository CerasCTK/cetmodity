#ifndef CETMODITY_LLIST_ITEM_H
#define CETMODITY_LLIST_ITEM_H

#include "bool.h"
#include "item.h"

typedef struct item_node {
    item item;
    struct item_node *next, *prev;
} item_node;

typedef struct dllist_item {
    item_node *head;
    item_node *tail;
} dllist_item;

void di_init(dllist_item *list);

bool di_is_empty(dllist_item list);

bool di_is_in_list(dllist_item list, item item);

int di_size(dllist_item list);

void di_insert_end(dllist_item *list, item item);

item_node *di_get_by_index(dllist_item list, int index);

item_node *
di_search_node_by_product_name(dllist_item list, const char *item_name);

item_node *di_search_node_by_product_name_input(dllist_item list);

void di_delete(dllist_item *list, item_node *node);

unsigned long di_calculate_total_price(dllist_item list);

void di_free(dllist_item *list);

#endif // !CETMODITY_LLIST_ITEM_H
