#include "dllist_deliver.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dd_init(dllist_deliver *list) {
    list->head = NULL;
    list->tail = NULL;
}

bool dd_is_empty(dllist_deliver list) {
    return list.head == NULL && list.tail == NULL;
}

bool dd_is_in_list(dllist_deliver list, deliver deliver) {
    if (dd_is_empty(list))
        return false;

    while (list.head != NULL) {
        if (is_same_deliver(list.head->deliver, deliver))
            return true;
        list.head = list.head->next;
    }

    return false;
}

int dd_size(dllist_deliver list) {
    if (dd_is_empty(list))
        return 0;

    int count = 0;
    while (list.head != NULL) {
        count++;
        list.head = list.head->next;
    }

    return count;
}

void dd_insert_begin(dllist_deliver *list, deliver deliver) {
    deliver_node *node = (deliver_node *)malloc(sizeof(deliver_node));
    node->deliver = deliver;
    node->prev = NULL;

    if (dd_is_empty(*list)) {
        list->tail = node;
        node->next = NULL;
    } else {
        node->next = list->head;
        list->head->prev = node;
    }
    list->head = node;
}

void dd_insert_end(dllist_deliver *list, deliver deliver) {
    deliver_node *node = (deliver_node *)malloc(sizeof(deliver_node));
    node->deliver = deliver;
    node->next = NULL;

    if (dd_is_empty(*list)) {
        list->head = node;
        node->prev = NULL;
    } else {
        node->prev = list->tail;
        list->tail->next = node;
    }
    list->tail = node;
}

void dd_insert_after(
    dllist_deliver *list, deliver_node *node, deliver deliver
) {
    if (dd_is_empty(*list))
        return;
    if ((dd_is_in_list(*list, deliver))
        || !(dd_is_in_list(*list, node->deliver)))
        return;

    deliver_node *new_node = (deliver_node *)malloc(sizeof(deliver_node));
    new_node->deliver = deliver;

    if (list->tail == node) {
        dd_insert_end(list, deliver);
    } else {
        new_node->next = node->next;
        node->next->prev = new_node;
        node->next = new_node;
        new_node->prev = node;
    }
}

void dd_insert_before(
    dllist_deliver *list, deliver_node *node, deliver deliver
) {
    if (dd_is_empty(*list))
        return;
    if ((dd_is_in_list(*list, deliver))
        || !(dd_is_in_list(*list, node->deliver)))
        return;

    deliver_node *new_node = (deliver_node *)malloc(sizeof(deliver_node));
    new_node->deliver = deliver;

    if (list->head == node) {
        dd_insert_begin(list, deliver);
    } else {
        new_node->prev = node->prev;
        node->prev->next = new_node;
        new_node->next = node;
        node->prev = new_node;
    }
}

deliver_node *dd_get_by_index(dllist_deliver list, int index) {
    if (dd_is_empty(list))
        return NULL;

    if (index < 0 || index > (dd_size(list) - 1))
        return NULL;

    if (index == 0)
        return list.head;
    if (index == dd_size(list) - 1)
        return list.tail;

    int count = 0;
    deliver_node *node = list.head;
    while (node != NULL) {
        if (count == index)
            return node;
        count++;
        node = node->next;
    }

    return NULL;
}

deliver_node *dd_search_node_by_name(dllist_deliver list, char *deliver_name) {
    if (dd_is_empty(list))
        return NULL;

    deliver_node *node = list.head;

    while (node != NULL) {
        if (strcmp(deliver_name, node->deliver.name) == 0)
            return node;
        node = node->next;
    }

    return NULL;
}

deliver_node *
dd_find_user(dllist_deliver list, char *username, char *password) {
    if (dd_is_empty(list))
        return NULL;

    for (deliver_node *runner = list.head; runner != NULL;
         runner = runner->next) {
        if (strcmp(runner->deliver.account.username, username) == 0
            && strcmp(runner->deliver.account.password, password) == 0) {
            return runner;
        }
    }

    return NULL;
}

void dd_delete(dllist_deliver *list, deliver_node *node) {
    if (dd_is_empty(*list))
        return;
    if (!(dd_is_in_list(*list, node->deliver)))
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

void dd_delete_begin(dllist_deliver *list) { dd_delete(list, list->head); }

void dd_delete_end(dllist_deliver *list) { dd_delete(list, list->tail); }

void dd_delete_before(dllist_deliver *list, deliver_node *node) {
    if (node == list->head)
        return;
    dd_delete(list, node->prev);
}

void dd_delete_after(dllist_deliver *list, deliver_node *node) {
    if (node == list->tail)
        return;
    dd_delete(list, node->next);
}

void dd_free(dllist_deliver *list) {
    if (dd_is_empty(*list))
        return;

    deliver_node *temp = list->head;
    while (temp != NULL) {
        deliver_node *new_temp = temp;

        temp = temp->next;
        free(new_temp);
    }

    list->head = list->tail = NULL;
}
