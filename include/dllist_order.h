#ifndef CETMODITY_LLIST_ORDER_H
#define CETMODITY_LLIST_ORDER_H

#include "bool.h"
#include "order.h"

struct _order_node {
    order order;
    struct _order_node *next, *prev;
};
typedef struct _order_node order_node;

struct _dllist_order {
    order_node *head;
    order_node *tail;
};
typedef struct _dllist_order dllist_order;

void do_init(dllist_order *);

bool do_is_empty(dllist_order);

bool do_is_in_list(dllist_order, order);

int do_size(dllist_order);

void do_insert_begin(dllist_order *, order);

void do_insert_end(dllist_order *, order);

void do_insert_after(dllist_order *, order_node *, order);

void do_insert_before(dllist_order *, order_node *, order);

order_node *do_get_by_index(dllist_order, int);

order_node *do_search_by_id(dllist_order, char *);

order_node *do_search_by_sender_name(dllist_order, char *);

order_node *do_search_by_receiver_name(dllist_order, char *);

void do_delete_by_id(dllist_order *, char *);

void do_delete_before(dllist_order *, order_node *);

void do_delete_after(dllist_order *, order_node *);

void do_delete(dllist_order *, order_node *);

void do_free(dllist_order *);

#endif // !CETMODITY_LLIST_ORDER_H
