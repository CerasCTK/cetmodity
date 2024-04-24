#ifndef CETMODITY_LLIST_ORDER_H
#define CETMODITY_LLIST_ORDER_H

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

#endif // !CETMODITY_LLIST_ORDER_H
