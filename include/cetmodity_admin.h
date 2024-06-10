#ifndef CETMODITY_CETMODITY_ADMIN_H
#define CETMODITY_CETMODITY_ADMIN_H

#include "dllist_deliver.h"

/**
 * @brief Add new deliver to the list
 *
 * @param list List of deliver to add new deliver
 */
void add_new_deliver(dllist_deliver *const list);

/**
 * @brief Display deliver information from the list and user input deliver id to
 * search that deliver
 *
 * @param list List of deliver contain deliver to display information
 */
void display_deliver_information(const dllist_deliver *const list);

/**
 * @brief Edit exist deliver in the list and user input deliver id to search
 * that deliver
 *
 * @param list List of deliver contain deliver to edit
 */
void edit_deliver_information(const dllist_deliver *const list);

/**
 * @brief Delete the exist deliver from the list and user input deliver id to
 * search that deliver
 *
 * @param list List of deliver contain deliver to delete
 */
void delete_deliver(dllist_deliver *const list);

/**
 * @brief Add new order to the list
 *
 * @param list List of order to add new order
 */
void add_new_order(dllist_order *const list);

/**
 * @brief Display order information from the list and user input order id to
 * search that order
 *
 * @param list List of order contain order to display information
 */
void display_order_information(const dllist_order *const list);

/**
 * @brief Edit exist order in the list and user input order id to search that
 * order
 *
 * @param list List of order contain order to edit
 */
void edit_order_information(const dllist_order *const list);

/**
 * @brief Delete the exist order from the list and user input order id to search
 * that order
 *
 * @param list List of order contain order to delete
 */
void delete_order(dllist_order *const list);

/**
 * @brief Distribute order to deliver
 *
 * @param list_order List of order to distribute
 * @param list_deliver List of deliver to distribute
 */
void distribute_order_to_deliver(
    dllist_order *const list_order, dllist_deliver *const list_deliver
);

#endif // !CETMODITY_CETMODITY_ADMIN_H
