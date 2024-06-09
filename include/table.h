#ifndef CETMODITY_TABLE_H
#define CETMODITY_TABLE_H

#include "dllist_deliver.h"
#include "dllist_order.h"

#define TABLE_BORDER_X                                                         \
    "------------------------------------------------------------------------" \
    "------------------------------------------------------------------------" \
    "----------------------------------"

void show_order_table_for_manager(
    const dllist_order *const list_order,
    const dllist_deliver *const list_deliver
);

void show_order_table_for_deliver(const deliver *const deliver);

void show_order_detail(const order *const order);

void show_deliver_table(const dllist_deliver *const list_deliver);

#endif
