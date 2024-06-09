#include "dllist_order.h"

#include "dllist_item.h"
#include "io_util.h"
#include "order.h"
#include "uuid_util.h"

#include <bool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void do_init(dllist_order **const list) {
    *list = malloc(sizeof(dllist_order));

    (*list)->head = NULL;
    (*list)->tail = NULL;
}

const bool do_is_empty(const dllist_order *const list) {
    return list->head == NULL && list->tail == NULL;
}

const bool
do_is_in_list(const dllist_order *const list, const order *const order) {
    if (do_is_empty(list))
        return false;

    for (order_node *runner = list->head; runner != NULL; runner = runner->next)
        if (is_same_order(runner->order, order))
            return true;

    return false;
}

const int do_size(const dllist_order *const list) {
    if (do_is_empty(list))
        return 0;

    int counter = 0;
    for (order_node *runner = list->head; runner != NULL; runner = runner->next)
        counter++;

    return counter;
}

const bool do_insert(dllist_order *const list, order *const new_order) {
    order_node *new_node = malloc(sizeof(order_node));

    new_node->order = new_order;
    new_node->next = NULL;

    if (do_is_empty(list)) {
        new_node->prev = NULL;
        list->head = new_node;
    } else {
        new_node->prev = list->tail;
        list->tail->next = new_node;
    }

    list->tail = new_node;

    return true;
}

order_node *const do_get_by_index(const dllist_order *const list, int index) {
    if (do_is_empty(list))
        return NULL;

    if (index >= do_size(list) || index < 0)
        return NULL;

    if (index == 0)
        return list->head;
    if (index == do_size(list) - 1)
        return list->tail;

    order_node *runner = list->head;
    while (index-- != -1)
        runner = runner->next;

    return runner;
}

order_node *const
do_search_by_id(const dllist_order *const list, const char *order_id) {
    if (do_is_empty(list))
        return NULL;

    for (order_node *runner = list->head; runner != NULL; runner = runner->next)
        if (strcmp(runner->order->id, order_id) == 0)
            return runner;

    return NULL;
}

order_node *const do_search_by_id_input(const dllist_order *const list) {
    char order_id[ID_LEN];

    printf("Input order's ID to search: ");
    input_string(order_id, ID_LEN);

    return do_search_by_id(list, order_id);
}

void do_delete(dllist_order *const list, order_node *const node) {
    if (do_is_empty(list))
        return;

    if (!do_is_in_list(list, node->order))
        return;

    if (node == list->head)
        list->head = node->next;
    else
        node->prev->next = node->next;

    if (node == list->tail)
        list->tail = node->prev;
    else
        node->next->prev = node->prev;

    free(node);
}

void do_free(dllist_order *list) {
    if (do_is_empty(list))
        return;

    order_node *runner = list->head;
    while (runner != NULL) {
        order_node *temp = runner;

        runner = runner->next;

        di_free(temp->order->item_list);
        free(temp->order);
        free(temp);
    }

    list->head = list->tail = NULL;
}
