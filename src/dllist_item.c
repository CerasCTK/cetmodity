#include "dllist_item.h"

#include <stdio.h>
#include <stdlib.h>

void di_init(dllist_item *list) {
    list->head = NULL;
    list->tail = NULL;
}

bool di_is_empty(dllist_item list) {
    return !list.head && !list.tail;
}

bool di_is_in_list(dllist_item list, item item) {
    if (di_is_empty(list)) return false;

    while (list.head != NULL) {
        if (is_same_item(list.head->item, item)) return true;
        list.head = list.head->next;
    }

    return false;
}

int di_size(dllist_item list) {
    if (di_is_empty(list)) return 0;

    int counter = 0;
    while (list.head != NULL) {
        counter++;
        list.head = list.head->next;
    }

    return counter;
}

void di_insert_begin(dllist_item *list, item item) {
    if (di_is_empty(*list)) return;

    item_node *new_node = (item_node *)malloc(sizeof(item_node));
    new_node->item = item;
    new_node->prev = NULL;

    new_node->next = list->head;
    list->head->prev = new_node;
    list->head = new_node;
}

