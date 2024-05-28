#ifndef CETMODIDTY_LLIST_DELIVER_H
#define CETMODIDTY_LLIST_DELIVER_H

#include "bool.h"
#include "deliver.h"

typedef struct deliver_node {
    deliver deliver;
    struct deliver_node *next, *prev;
} deliver_node;

typedef struct dllist_deliver {
    deliver_node *head;
    deliver_node *tail;
} dllist_deliver;

void dd_init(dllist_deliver *list);

bool dd_is_empty(dllist_deliver list);

bool dd_is_in_list(dllist_deliver list, deliver deliver);

int dd_size(dllist_deliver list);

void dd_insert_begin(dllist_deliver *list, deliver deliver);

void dd_insert_end(dllist_deliver *list, deliver deliver);

void dd_insert_after(dllist_deliver *list, deliver_node *node, deliver deliver);

void dd_insert_before(
    dllist_deliver *list, deliver_node *node, deliver deliver
);

deliver_node *dd_get_by_index(dllist_deliver list, int index);

deliver_node *
dd_search_node_by_name(dllist_deliver list, const char *deliver_name);

deliver_node *
dd_search_node_by_phone_number(dllist_deliver list, const char *deliver_phone_number);

deliver_node *
dd_find_user(dllist_deliver list, const char *username, const char *password);

void dd_delete(dllist_deliver *list, deliver_node *node);

void dd_delete_begin(dllist_deliver *list);

void dd_delete_end(dllist_deliver *list);

void dd_delete_before(dllist_deliver *list, const deliver_node *node);

void dd_delete_after(dllist_deliver *list, const deliver_node *node);

void dd_free(dllist_deliver *list);

#endif // !CETMODIDTY_LLIST_DELIVER_H
