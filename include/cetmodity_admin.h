#ifndef CETMODITY_CETMODITY_ADMIN_H
#define CETMODITY_CETMODITY_ADMIN_H

#include "dllist_deliver.h"

// Deliver
/**
 * @brief Add new deliver to the list
 *
 * @param list List of deliver to add new deliver
 */
void add_new_deliver(dllist_deliver *list);

/**
 * @brief Display deliver information from the list and user input deliver id to
 * search that deliver
 *
 * @param list List of deliver contain deliver to display information
 */
void display_deliver_information(dllist_deliver list);

/**
 * @brief Edit exist deliver in the list and user input deliver id to search
 * that deliver
 *
 * @param list List of deliver contain deliver to edit
 */
void edit_deliver_information(dllist_deliver *list);

/**
 * @brief Delete the exist deliver from the list and user input deliver id to
 * search that deliver
 *
 * @param list List of deliver contain deliver to delete
 */
void delete_deliver(dllist_deliver *list);

// Order
/**
 * @brief Add new order to the list
 *
 * @param list List of order to add new order
 */
void add_new_order(dllist_order *list);

/**
 * @brief Display order information from the list and user input order id to
 * search that order
 *
 * @param list List of order contain order to display information
 */
void display_order_information(dllist_order list);

/**
 * @brief Edit exist order in the list and user input order id to search that
 * order
 *
 * @param list List of order contain order to edit
 */
void edit_order_information(dllist_order *list);

/**
 * @brief Delete the exist order from the list and user input order id to search
 * that order
 *
 * @param list List of order contain order to delete
 */
void delete_order(dllist_order *list);

#endif // !CETMODITY_CETMODITY_ADMIN_H
