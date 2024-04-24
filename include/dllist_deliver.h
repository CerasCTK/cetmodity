#ifndef CETMODIDTY_LLIST_DELIVER_H
#define CETMODIDTY_LLIST_DELIVER_H

#include "bool.h"
#include "deliver.h"

struct _deliver_node {
    deliver deliver;
    struct _deliver_node *next, *prev;
};
typedef struct _deliver_node deliver_node;

struct _dllist_deliver {
    deliver_node *head;
    deliver_node *tail;
};
typedef struct _dllist_deliver dllist_deliver;

void dd_init(dllist_deliver *);

bool dd_is_empty(dllist_deliver);

bool dd_is_in_list(dllist_deliver, deliver);

int dd_size(dllist_deliver);

void dd_insert_begin(dllist_deliver *, deliver);

void dd_insert_end(dllist_deliver *, deliver);

void dd_insert_after(dllist_deliver *, deliver_node *, deliver);

void dd_insert_before(dllist_deliver *, deliver_node *, deliver);

deliver_node *dd_get_by_index(dllist_deliver, int);

void dd_delete(dllist_deliver *, deliver_node *);

void dd_delete_begin(dllist_deliver *);

void dd_delete_end(dllist_deliver *);

void dd_delete_before(dllist_deliver *, deliver_node *);

void dd_delete_after(dllist_deliver *, deliver_node *);

void dd_free(dllist_deliver *);

#endif // !CETMODIDTY_LLIST_DELIVER_H
