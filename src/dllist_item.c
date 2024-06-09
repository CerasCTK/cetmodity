#include "dllist_item.h"

#include <io_util.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void di_init(dllist_item *const list) {
    list->head = NULL;
    list->tail = NULL;
}

const bool di_is_empty(const dllist_item *const list) {
    return list->head == NULL && list->tail == NULL;
}

const bool
di_is_in_list(const dllist_item *const list, const item *const item) {
    if (di_is_empty(list))
        return false;

    const item_node *runner = list->head;
    while (runner != NULL) {
        if (is_same_item(list->head->item, item))
            return true;

        runner = runner->next;
    }

    return false;
}

const int di_size(const dllist_item *list) {
    if (di_is_empty(list))
        return 0;

    int counter = 0;
    item_node *runner = list->head;
    while (runner != NULL) {
        counter++;
        runner = runner->next;
    }

    return counter;
}

void di_insert_end(dllist_item *const list, item *const item) {
    // Check if the product is in list, we will replace the old one
    item_node *const node
        = di_search_node_by_product_name(list, item->product_name);
    if (node != NULL) {
        free(node->item); // Remove old item

        node->item = item;
        return;
    }

    item_node *new_node = malloc(sizeof(item_node));
    new_node->item = item;
    new_node->next = NULL;

    if (di_is_empty(list)) {
        new_node->prev = NULL;
        list->head = new_node;
    } else {
        new_node->prev = list->tail;
        list->tail->next = new_node;
    }
    list->tail = new_node;
}

item_node *const
di_get_by_index(const dllist_item *const list, const int index) {
    if (di_is_empty(list))
        return NULL;

    if (index < 0 || index >= di_size(list))
        return NULL;

    if (index == 0)
        return list->head;
    if (index == di_size(list) - 1)
        return list->tail;

    item_node *node = list->head;
    int count = 0;
    while (node != NULL) {
        if (count == index)
            return node;
        count++;
        node = node->next;
    }

    return NULL;
}

item_node *const di_search_node_by_product_name(
    const dllist_item *const list, const char *const item_name
) {
    if (di_is_empty(list))
        return NULL;

    item_node *node = list->head;

    while (node != NULL) {
        if (strcmp(item_name, node->item->product_name) == 0)
            return node;
        node = node->next;
    }

    return NULL;
}

item_node *di_search_node_by_product_name_input(const dllist_item *const list) {
    char name[PRODUCT_MAX_NAME_LEN];

    printf("Input product's name to search: ");
    input_string(name, PRODUCT_MAX_NAME_LEN);

    return di_search_node_by_product_name(list, name);
}

void di_delete(dllist_item *const list, item_node *const node) {
    if (di_is_empty(list))
        return;
    if (!(di_is_in_list(list, node->item)))
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

const unsigned long di_calculate_total_price(const dllist_item *const list) {
    if (di_is_empty(list))
        return 0;

    unsigned long total = 0;
    for (item_node *runner = list->head; runner != NULL;
         runner = runner->next) {
        total += runner->item->unit_price * runner->item->quantity;
    }

    return total;
}

void di_free(dllist_item *list) {
    if (di_is_empty(list))
        return;

    item_node *runner = list->head;
    while (runner != NULL) {
        item_node *temp = runner;

        runner = runner->next;
        free(temp->item);
        free(temp);
    }

    list->head = list->tail = NULL;
}
