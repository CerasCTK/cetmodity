#ifndef CETMODITY_LLIST_ORDER_H
#define CETMODITY_LLIST_ORDER_H

#include "bool.h"
#include "order.h"

typedef struct order_node {
    order *order;
    struct order_node *next, *prev;
} order_node;

typedef struct dllist_order {
    order_node *head;
    order_node *tail;
} dllist_order;

void do_init(dllist_order *const list);

const bool do_is_empty(const dllist_order *const list);

const bool do_is_in_list(const dllist_order *list, const order *const order);

const int do_size(const dllist_order *const list);

const bool do_insert_end(dllist_order *const list, order *const order);

order_node *const do_get_by_index(const dllist_order *const list, int index);

order_node *const
do_search_by_id(const dllist_order *const list, const char *order_id);

order_node *const do_search_by_id_input(const dllist_order *const list);

void do_delete(dllist_order *const list, order_node *const node);

void do_free(dllist_order *list);

#endif // !CETMODITY_LLIST_ORDER_H
