#ifndef CETMODITY_MENU_H
#define CETMODITY_MENU_H

#include "dllist_deliver.h"
#include "dllist_order.h"

void logout_menu();

void a_show_menu();

void a_show_manage_delivers_menu(dllist_deliver list);

void a_show_manage_orders_menu(dllist_order order_list, dllist_deliver deliver_list);

void d_show_menu();

bool confirm_menu(char *msg);

#endif // !CETMODITY_MENU_H
