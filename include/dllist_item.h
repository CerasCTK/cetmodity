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

void di_init(dllist_item *list);

bool di_is_empty(dllist_item list);

bool di_is_in_list(dllist_item list, item item);

int di_size(dllist_item list);

char** di_get_list_in_string(dllist_item list);

void di_free_string_list(char **string_list, int size);

void di_insert_begin(dllist_item *list, item item);

void di_insert_end(dllist_item *list, item item);

void di_insert_after(dllist_item *list, item_node *node, item item);

void di_insert_before(dllist_item *list, item_node *node, item item);

item_node *di_get_by_index(dllist_item list, int index);

item_node *di_search_node_by_name(dllist_item list, char *item_name);

void di_delete(dllist_item *list, item_node *node);

void di_delete_begin(dllist_item *list);

void di_delete_end(dllist_item *list);

void di_delete_before(dllist_item *list, item_node *node);

void di_delete_after(dllist_item *list, item_node *node);

unsigned long di_calculate_total_price(dllist_item list);

void di_free(dllist_item *list);

#endif // !CETMODITY_LLIST_ITEM_H
