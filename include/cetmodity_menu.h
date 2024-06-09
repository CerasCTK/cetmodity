#ifndef CETMODITY_MENU_H
#define CETMODITY_MENU_H

#include "dllist_deliver.h"
#include "dllist_order.h"

void logout_menu();

const bool confirm_menu(char *msg);

void admin_menu();

void admin_manage_delivers_menu(const dllist_deliver *const list);

void admin_manage_orders_menu(
    const dllist_order *const order_list,
    const dllist_deliver *const deliver_list
);

void deliver_menu(const deliver *const deliver);

#endif // !CETMODITY_MENU_H
