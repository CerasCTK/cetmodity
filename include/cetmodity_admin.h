#ifndef CETMODITY_ADMIN_H
#define CETMODITY_ADMIN_H

#include "dllist_deliver.h"

void add_new_deliver(dllist_deliver *list);

void edit_deliver_information(dllist_deliver *list);

void delete_deliver(dllist_deliver *list);

void add_new_order(dllist_order *list);

void edit_order_information(dllist_order *list);

void delete_order(dllist_order *list);

#endif // !CETMODITY_ADMIN_H
