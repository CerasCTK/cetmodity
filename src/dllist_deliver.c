#include "dllist_deliver.h"

#include "io_util.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dd_init(dllist_deliver *list) {
    list->head = NULL;
    list->tail = NULL;
}

bool dd_is_empty(const dllist_deliver list) {
    return list.head == NULL && list.tail == NULL;
}

bool dd_is_in_list(dllist_deliver list, const deliver deliver) {
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

bool dd_insert_end(dllist_deliver *list, const deliver deliver) {
    deliver_node *node = malloc(sizeof(deliver_node));

    if (node == NULL) {
        printf("Memory not allocated\n");
        return false;
    }

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

    return true;
}

deliver_node *dd_get_by_index(const dllist_deliver list, const int index) {
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

deliver_node *
dd_search_node_by_name(const dllist_deliver list, const char *deliver_name) {
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
dd_search_node_by_id(dllist_deliver list, const char *deliver_id) {
    if (dd_is_empty(list))
        return NULL;

    deliver_node *node = list.head;

    while (node != NULL) {
        if (strcmp(deliver_id, node->deliver.id) == 0)
            return node;
        node = node->next;
    }

    return NULL;
}

deliver_node *dd_search_node_by_id_input(dllist_deliver list) {
    char id[ID_LEN];

    printf("Input deliver's ID to edit: ");
    input_string(id, ID_LEN);

    deliver_node *node = dd_search_node_by_id(list, id);

    return node;
}

deliver_node *dd_find_user(
    const dllist_deliver list, const char *username, const char *password
) {
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

bool dd_delete(dllist_deliver *list, deliver_node *node) {
    if (dd_is_empty(*list))
        return false;
    if (!(dd_is_in_list(*list, node->deliver)))
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
