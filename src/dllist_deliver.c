#include "dllist_deliver.h"

#include "deliver.h"
#include "dllist_order.h"
#include "io_util.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dd_init(dllist_deliver **const list) {
    *list = malloc(sizeof(dllist_deliver));

    if (*list == NULL) {
        printf("Memory not allocated\n");
        return;
    }

    (*list)->head = NULL;
    (*list)->tail = NULL;
}

const bool dd_is_empty(const dllist_deliver *const list) {
    return list->head == NULL && list->tail == NULL;
}

const bool
dd_is_in_list(const dllist_deliver *const list, const deliver *const deliver) {
    if (dd_is_empty(list))
        return false;

    deliver_node *runner = list->head;
    while (runner != NULL) {
        if (is_same_deliver(runner->deliver, deliver))
            return true;
        runner = runner->next;
    }

    return false;
}

const int dd_size(const dllist_deliver *const list) {
    if (dd_is_empty(list))
        return 0;

    int count = 0;
    deliver_node *runner = list->head;
    while (runner != NULL) {
        count++;
        runner = runner->next;
    }

    return count;
}

const bool dd_insert(dllist_deliver *const list, deliver *const deliver) {
    deliver_node *node = malloc(sizeof(deliver_node));

    if (node == NULL) {
        printf("Memory not allocated\n");
        return false;
    }

    node->deliver = deliver;
    node->next = NULL;

    if (dd_is_empty(list)) {
        list->head = node;
        node->prev = NULL;
    } else {
        node->prev = list->tail;
        list->tail->next = node;
    }
    list->tail = node;

    return true;
}

deliver_node *const
dd_get_by_index(const dllist_deliver *const list, int index) {
    if (dd_is_empty(list))
        return NULL;

    if (index < 0 || index > (dd_size(list) - 1))
        return NULL;

    if (index == 0)
        return list->head;
    if (index == dd_size(list) - 1)
        return list->tail;

    int count = 0;
    deliver_node *node = list->head;
    while (node != NULL) {
        if (count == index)
            return node;
        count++;
        node = node->next;
    }

    return NULL;
}

deliver_node *const
dd_search_node_by_id(const dllist_deliver *const list, const char *deliver_id) {
    if (dd_is_empty(list))
        return NULL;

    deliver_node *node = list->head;

    while (node != NULL) {
        if (strcmp(deliver_id, node->deliver->id) == 0)
            return node;
        node = node->next;
    }

    return NULL;
}

deliver_node *const dd_search_node_by_id_input(const dllist_deliver *const list
) {
    char id[ID_LEN];

    printf("Input deliver's ID to search: ");
    input_string(id, ID_LEN);

    deliver_node *node = dd_search_node_by_id(list, id);

    return node;
}

deliver_node *const dd_find_user(
    const dllist_deliver *const list, const char *username, const char *password
) {
    if (dd_is_empty(list))
        return NULL;

    for (deliver_node *runner = list->head; runner != NULL;
         runner = runner->next) {
        if (strcmp(runner->deliver->account.username, username) == 0
            && strcmp(runner->deliver->account.password, password) == 0) {
            return runner;
        }
    }

    return NULL;
}

const bool dd_delete(dllist_deliver *const list, deliver_node *node) {
    if (dd_is_empty(list))
        return false;
    if (!(dd_is_in_list(list, node->deliver)))
        return false;

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
    return true;
}

void dd_free(dllist_deliver *const list) {
    if (dd_is_empty(list))
        return;

    deliver_node *runner = list->head;
    while (runner != NULL) {
        deliver_node *temp = runner;

        runner = runner->next;

        free(temp->deliver);
        free(temp);
    }

    list->head = list->tail = NULL;
}
