#ifndef CETMODITY_LLIST_ORDER_H
#define CETMODITY_LLIST_ORDER_H

#include "bool.h"
#include "order.h"

/**
 * @typedef order_node
 * @brief Struct of a node in the linked list of order.
 *
 */
typedef struct order_node {
    order *order;
    struct order_node *next, *prev;
} order_node;

/**
 * @typedef dllist_order
 * @brief Struct of doubly linked list of orders.
 *
 */
typedef struct dllist_order {
    order_node *head;
    order_node *tail;
} dllist_order;

/**
 * @brief Initialize a doubly linked list of orders.
 *
 * @param list List to be initialized.
 */
void do_init(dllist_order **const list);

/**
 * @brief Check if the list is empty.
 *
 * @param list List to be checked.
 * @return true if the list is empty, false otherwise.
 */
const bool do_is_empty(const dllist_order *const list);

/**
 * @brief Check if the order is in the list.
 *
 * @param list List to be checked.
 * @param order Order to be checked.
 * @return true if the order is in the list, false otherwise.
 */
const bool do_is_in_list(const dllist_order *list, const order *const order);

/**
 * @brief Get the size of the list.
 *
 * @param list List to get the size.
 * @return Size of the list.
 */
const int do_size(const dllist_order *const list);

/**
 * @brief Insert an order to the end of the list.
 *
 * @param list List where store the order.
 * @param order Order to be inserted.
 * @return true if the order is inserted, false otherwise.
 */
const bool do_insert(dllist_order *const list, order *const order);

/**
 * @brief Get the order by index.
 *
 * @param list List to get the order.
 * @param index Index of the order.
 * @return order_node* if the index is valid, NULL otherwise.
 */
order_node *const do_get_by_index(const dllist_order *const list, int index);

/**
 * @brief Search the order by id.
 *
 * @param list List to get the order.
 * @param order_id ID of the order.
 * @return order_node* if the order is found, NULL otherwise.
 */
order_node *const
do_search_by_id(const dllist_order *const list, const char *order_id);

/**
 * @brief Search the order by id get from input.
 *
 * @param list List to get the order.
 * @return order_node* if the order is found, NULL otherwise.
 */
order_node *const do_search_by_id_input(const dllist_order *const list);

/**
 * @brief Delete an order from the list.
 *
 * @param list List has the order to be deleted.
 * @param node Node of the order.
 */
void do_delete(dllist_order *const list, order_node *const node);

/**
 * @brief Free the memory of the list.
 *
 * @param list List to be free.
 */
void do_free(dllist_order *list);

#endif // !CETMODITY_LLIST_ORDER_H
