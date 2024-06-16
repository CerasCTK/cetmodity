#ifndef CETMODITY_DATABASE_H
#define CETMODITY_DATABASE_H

#include "dllist_deliver.h"
#include "dllist_order.h"

void load_database(dllist_deliver *const delivers, dllist_order *const orders);

void stop_database();

#endif // !CETMODITY_DATABASE_H
