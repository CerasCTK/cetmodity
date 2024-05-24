#ifndef CETMODITY_TABLE_H
#define CETMODITY_TABLE_H

#include "dllist_order.h"
#include "dllist_deliver.h"

#define TABLE_BORDER_X                                                         \
    "------------------------------------------------------------------------" \
    "------------------------------------------------------------------------"

void show_order_table(dllist_order list_order);

void show_deliver_table(dllist_deliver list_deliver);

#endif
