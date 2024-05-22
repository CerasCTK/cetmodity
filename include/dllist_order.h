#ifndef CETMODITY_LLIST_ORDER_H
#define CETMODITY_LLIST_ORDER_H

#include "bool.h"
#include "order.h"

typedef struct order_node {
    order order;
    struct order_node *next, *prev;
} order_node;

typedef struct dllist_order {
    order_node *head;
    order_node *tail;
} dllist_order;

void do_init(dllist_order *list);

bool do_is_empty(dllist_order list);

bool do_is_in_list(dllist_order list, order order);

int do_size(dllist_order list);

void do_insert_begin(dllist_order *list, order order);

void do_insert_end(dllist_order *list, order order);

void do_insert_after(dllist_order *list, order_node *node, order order);

void do_insert_before(dllist_order *list, order_node *node, order order);

order_node *do_get_by_index(dllist_order list, int index);

order_node *do_search_by_id(dllist_order list, const char *order_id);

order_node *do_search_by_sender_name(dllist_order list, const char *sender_name);

order_node *do_search_by_receiver_name(dllist_order list, const char *receiver_name);

void do_delete(dllist_order *list, order_node *node);

void do_delete_begin(dllist_order *list);

void do_delete_end(dllist_order *list);

void do_delete_by_id(dllist_order *list, const char *order_id);

void do_delete_before(dllist_order *list, const order_node *node);

void do_delete_after(dllist_order *list, const order_node *node);

void do_free(dllist_order *list);

#endif // !CETMODITY_LLIST_ORDER_H
