#ifndef CETMODITY_TABLE_H
#define CETMODITY_TABLE_H

#include "dllist_deliver.h"
#include "dllist_order.h"

#define TABLE_BORDER_X                                                         \
    "------------------------------------------------------------------------" \
    "------------------------------------------------------------------------" \
    "----------------------------------"

void show_order_table_for_manager(
    dllist_order list_order, dllist_deliver list_deliver
);

void show_order_table_for_deliver(deliver deliver);

void show_order_detail(order order);

void show_deliver_table(dllist_deliver list_deliver);

#endif
