#ifndef CETMODIDTY_LLIST_DELIVER_H
#define CETMODIDTY_LLIST_DELIVER_H

#include "bool.h"
#include "deliver.h"

typedef struct deliver_node {
    deliver *deliver;
    struct deliver_node *next, *prev;
} deliver_node;

typedef struct dllist_deliver {
    deliver_node *head;
    deliver_node *tail;
} dllist_deliver;

void dd_init(dllist_deliver *const list);

const bool dd_is_empty(const dllist_deliver *const list);

const bool
dd_is_in_list(const dllist_deliver *const list, const deliver *const deliver);

const int dd_size(const dllist_deliver *const list);

const bool dd_insert(dllist_deliver *const list, deliver *const deliver);

deliver_node *const
dd_get_by_index(const dllist_deliver *const list, int index);

deliver_node *const
dd_search_node_by_id(const dllist_deliver *const list, const char *deliver_id);

deliver_node *const dd_search_node_by_id_input(const dllist_deliver *const list
);

deliver_node *const dd_find_user(
    const dllist_deliver *const list, const char *username, const char *password
);

const bool dd_delete(dllist_deliver *const list, deliver_node *node);

void dd_free(dllist_deliver *const list);

#endif // !CETMODIDTY_LLIST_DELIVER_H
