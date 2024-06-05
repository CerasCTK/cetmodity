#include "dllist_item.h"

#include <io_util.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void di_init(dllist_item *list) {
    list->head = NULL;
    list->tail = NULL;
}

bool di_is_empty(const dllist_item list) {
    return list.head == NULL && list.tail == NULL;
}

bool di_is_in_list(dllist_item list, const item item) {
    if (di_is_empty(list))
        return false;

    while (list.head != NULL) {
        if (is_same_item(list.head->item, item))
            return true;
        list.head = list.head->next;
    }

    return false;
}

int di_size(dllist_item list) {
    if (di_is_empty(list))
        return 0;

    int counter = 0;
    while (list.head != NULL) {
        counter++;
        list.head = list.head->next;
    }

    return counter;
}

void di_insert_end(dllist_item *list, const item item) {
    item_node *new_node = malloc(sizeof(item_node));
    new_node->item = item;
    new_node->next = NULL;

    if (di_is_empty(*list)) {
        new_node->prev = NULL;
        list->head = new_node;
    } else {
        new_node->prev = list->tail;
        list->tail->next = new_node;
    }
    list->tail = new_node;
}

item_node *di_get_by_index(const dllist_item list, const int index) {
    if (di_is_empty(list))
        return NULL;

    if (index < 0 || index >= di_size(list))
        return NULL;

    if (index == 0)
        return list.head;
    if (index == di_size(list) - 1)
        return list.tail;

    item_node *node = list.head;
    int count = 0;
    while (node != NULL) {
        if (count == index)
            return node;
        count++;
        node = node->next;
    }

    return NULL;
}

item_node *di_search_node_by_product_name(
    const dllist_item list, const char *const item_name
) {
    if (di_is_empty(list))
        return NULL;

    item_node *node = list.head;

    while (node != NULL) {
        if (strcmp(item_name, node->item.product_name) == 0)
            return node;
        node = node->next;
    }

    return NULL;
}

item_node *di_search_node_by_product_name_input(dllist_item list) {
    char name[PRODUCT_MAX_NAME_LEN];

    printf("Input product's name to search: ");
    input_string(name, PRODUCT_MAX_NAME_LEN);

    return di_search_node_by_product_name(list, name);
}

void di_delete(dllist_item *list, item_node *node) {
    if (di_is_empty(*list))
        return;
    if (!(di_is_in_list(*list, node->item)))
        return;

    if (list->head == node && list->tail == node) {
        list->head = NULL;
        list->tail = NULL;
    } else if (list->head == node) {
        list->head = node->next;
        node->next->prev = NULL;
    } else if (list->tail == node) {
        list->tail = node->prev;
        node->prev->next = NULL;
    } else {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    free(node);
}

unsigned long di_calculate_total_price(const dllist_item list) {
    if (di_is_empty(list))
        return 0;

    unsigned long total = 0;
    for (item_node *runner = list.head; runner != NULL; runner = runner->next) {
        total += runner->item.unit_price * runner->item.quantity;
    }

    return total;
}

void di_free(dllist_item *list) {
    if (di_is_empty(*list))
        return;

    item_node *temp = list->head;
    while (temp != NULL) {
        item_node *new_temp = temp;

        temp = temp->next;
        free(new_temp);
    }

    list->head = list->tail = NULL;
}
