#include "dllist_order.h"

#include "dllist_item.h"
#include "order.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void do_init(dllist_order *list) { list->head = list->tail = NULL; }

bool do_is_empty(const dllist_order list) {
    return list.head == NULL && list.tail == NULL;
}

bool do_is_in_list(const dllist_order list, const order order) {
    if (do_is_empty(list))
        return false;

    for (order_node *runner = list.head; runner != NULL; runner = runner->next)
        if (is_same_order(runner->order, order))
            return true;

    return false;
}

int do_size(const dllist_order list) {
    if (do_is_empty(list))
        return 0;

    int counter = 0;
    for (order_node *runner = list.head; runner != NULL; runner = runner->next)
        counter++;

    return counter;
}

void do_insert_begin(dllist_order *list, const order new_order) {
    order_node *new_node = malloc(sizeof(order_node));
    new_node->order = new_order;
    new_node->prev = NULL;

    if (do_is_empty(*list)) {
        new_node->next = NULL;
        list->tail = new_node;
    } else {
        new_node->next = list->head;
        list->head->prev = new_node;
    }

    list->head = new_node;
}

void do_insert_end(dllist_order *list, order new_order) {
    order_node *new_node = malloc(sizeof(order_node));
    new_node->order = new_order;
    new_node->next = NULL;

    if (do_is_empty(*list)) {
        new_node->prev = NULL;
        list->head = new_node;
    } else {
        new_node->prev = list->tail;
        list->tail->next = new_node;
    }

    list->tail = new_node;
}

void do_insert_after(
    dllist_order *list, order_node *node, const order new_order
) {
    if (do_is_empty(*list))
        return;

    if (!do_is_in_list(*list, node->order))
        return;

    order_node *new_node = malloc(sizeof(order_node));
    new_node->order = new_order;
    new_node->next = node->next;
    new_node->prev = node;

    if (node == list->tail)
        list->tail = new_node;
    else
        node->next->prev = new_node;

    node->next = new_node;
}

void do_insert_before(
    dllist_order *list, order_node *node, const order new_order
) {
    if (do_is_empty(*list))
        return;

    if (!do_is_in_list(*list, node->order))
        return;

    order_node *new_node = malloc(sizeof(order_node));
    new_node->order = new_order;
    new_node->next = node;
    new_node->prev = node->prev;

    if (node == list->head)
        list->head = new_node;
    else
        node->prev->next = new_node;

    node->prev = new_node;
}

order_node *do_get_by_index(const dllist_order list, int index) {
    if (do_is_empty(list))
        return NULL;

    if (index >= do_size(list) || index < 0)
        return NULL;

    if (index == 0)
        return list.head;
    if (index == do_size(list) - 1)
        return list.tail;

    order_node *runner = list.head;
    while (index-- != -1)
        runner = runner->next;

    return runner;
}

order_node *do_search_by_id(const dllist_order list, const char *order_id) {
    if (do_is_empty(list))
        return NULL;

    for (order_node *runner = list.head; runner != NULL; runner = runner->next)
        if (strcmp(runner->order.id, order_id) == 0)
            return runner;

    return NULL;
}

order_node *do_search_by_id_input(dllist_order *list) {
    char order_id[UUID_STR_LEN + 1];

    printf("Input order'ID to edit: ");
    input_string(order_id, UUID_STR_LEN);

    return do_search_by_id(*list, order_id);
}

order_node *
do_search_by_sender_name(dllist_order list, const char *sender_name) {
    if (do_is_empty(list))
        return NULL;

    for (order_node *runner = list.head; runner != NULL; runner = runner->next)
        if (strcmp(runner->order.sender.name, sender_name) == 0)
            return runner;

    return NULL;
}

order_node *
do_search_by_receiver_name(dllist_order list, const char *receiver_name) {
    if (do_is_empty(list))
        return NULL;

    for (order_node *runner = list.head; runner != NULL; runner = runner->next)
        if (strcmp(runner->order.receiver.name, receiver_name) == 0)
            return runner;

    return NULL;
}

void do_delete(dllist_order *list, order_node *node) {
    if (do_is_empty(*list))
        return;

    if (!do_is_in_list(*list, node->order))
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

void do_delete_begin(dllist_order *list) { do_delete(list, list->head); }

void do_delete_end(dllist_order *list) { do_delete(list, list->tail); }

void do_delete_by_id(dllist_order *list, const char *order_id) {
    order_node *found = do_search_by_id(*list, order_id);

    do_delete(list, found);
}

void do_delete_before(dllist_order *list, const order_node *node) {
    do_delete(list, node->prev);
}

void do_delete_after(dllist_order *list, const order_node *node) {
    do_delete(list, node->next);
}

void do_free(dllist_order *list) {
    if (do_is_empty(*list))
        return;

    order_node *runner = list->head;
    while (runner != NULL) {
        order_node *temp = runner;

        runner = runner->next;

        di_free(&temp->order.items);
        free(temp);
    }

    list->head = list->tail = NULL;
}
