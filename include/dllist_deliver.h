#ifndef CETMODIDTY_LLIST_DELIVER_H
#define CETMODIDTY_LLIST_DELIVER_H

#include "bool.h"
#include "deliver.h"

/**
 * @typedef deliver_node
 * @brief Struct of a node in the linked list of deliver.
 *
 */
typedef struct deliver_node {
    deliver *deliver;
    struct deliver_node *next, *prev;
} deliver_node;

/**
 * @class dllist_deliver
 * @brief Struct of a doubly linked list of deliver.
 *
 */
typedef struct dllist_deliver {
    deliver_node *head;
    deliver_node *tail;
} dllist_deliver;

/**
 * @brief Initialize a doubly linked list of deliver.
 *
 * @param list List to be initialized.
 */
void dd_init(dllist_deliver *const list);

/**
 * @brief Check if the list is empty.
 *
 * @param list List to be checked.
 * @return true if the list is empty, false otherwise.
 */
const bool dd_is_empty(const dllist_deliver *const list);

/**
 * @brief Check if the deliver is in the list.
 *
 * @param list List to be checked.
 * @param deliver Deliver to be checked.
 * @return true if the deliver is in the list, false otherwise.
 */
const bool
dd_is_in_list(const dllist_deliver *const list, const deliver *const deliver);

/**
 * @brief Get the size of the list.
 *
 * @param list List to get the size.
 * @return Size of the list.
 */
const int dd_size(const dllist_deliver *const list);

/**
 * @brief Insert an order to the end of the list.
 *
 * @param list List where store the deliver.
 * @param deliver Deliver to be inserted.
 * @return true if the deliver is inserted, false otherwise.
 */
const bool dd_insert(dllist_deliver *const list, deliver *const deliver);

/**
 * @brief Get the deliver by index.
 *
 * @param list List to get the deliver.
 * @param index Index of the deliver.
 * @return deliver_node* if the index is valid, NULL otherwise.
 */
deliver_node *const
dd_get_by_index(const dllist_deliver *const list, int index);

/**
 * @brief Search the deliver by id.
 *
 * @param list List to get the deliver.
 * @param deliver_id ID of the deliver.
 * @return deliver_node* if the deliver is found, NULL otherwise.
 */
deliver_node *const
dd_search_node_by_id(const dllist_deliver *const list, const char *deliver_id);

/**
 * @brief Search the deliver by id get from input.
 *
 * @param list List to get the deliver.
 * @return deliver_node* if the deliver is found, NULL otherwise.
 */
deliver_node *const dd_search_node_by_id_input(const dllist_deliver *const list
);

/**
 * @brief Find the deliver by username and password.
 *
 * @param list List to find the deliver.
 * @param username Username of the deliver.
 * @param password Password of the deliver.
 * @return deliver_node* if the deliver is found, NULL otherwise.
 */
deliver_node *const dd_find_user(
    const dllist_deliver *const list, const char *username, const char *password
);

/**
 * @brief Delete an deliver from the list.
 *
 * @param list List has deliver to be deleted.
 * @param node Node of the deliver.
 * @return true if the deliver is deleted, false otherwise.
 */
const bool dd_delete(dllist_deliver *const list, deliver_node *node);

/**
 * @brief Free the memory of the list.
 *
 * @param list List to be free.
 */
void dd_free(dllist_deliver *const list);

#endif // !CETMODIDTY_LLIST_DELIVER_H
