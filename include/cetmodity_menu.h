#ifndef CETMODITY_MENU_H
#define CETMODITY_MENU_H

#include "dllist_deliver.h"
#include "dllist_order.h"

/**
 * @brief Show logout menu
 */
void logout_menu();

/**
 * @brief Show confirm menu
 *
 * @param msg Confirm message
 * @return Option of the user
 */
const bool confirm_menu(const char *const msg);

/**
 * @brief Show admin main menu
 */
void admin_manage_menu();

/**
 * @brief Show admin manage deliver menu
 *
 * @param list List of deliver
 */
void admin_manage_delivers_menu(const dllist_deliver *const list);

/**
 * @brief Show admin manage orders menu
 *
 * @param order_list List of order
 * @param deliver_list List of deliver
 */
void admin_manage_orders_menu(
    const dllist_order *const order_list,
    const dllist_deliver *const deliver_list
);

/**
 * @brief Show deliver manage menu
 *
 * @param deliver Deliver to manage
 */
void deliver_manage_menu(const deliver *const deliver);

#endif // !CETMODITY_MENU_H
