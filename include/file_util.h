#ifndef CETMODITY_FILE_UTIL_H
#define CETMODITY_FILE_UTIL_H

#include "bool.h"
#include "coordinate.h"
#include "deliver.h"
#include "dllist_deliver.h"
#include "dllist_item.h"
#include "dllist_order.h"
#include "item.h"
#include "order.h"
#include "sender.h"

#include <stdio.h>

bool is_file_exist(const char *const file_name);

void write_delivers_to_file(
    const char *const file_name, const dllist_deliver *const list
);

void write_deliver_to_file(FILE *const file, const deliver *const deliver);

void write_account_to_file(FILE *const file, const account account);

void write_orders_to_file(
    const char *const file_name, const dllist_order *const list
);

void write_order_to_file(FILE *const file, const order *const order);

void write_sender_to_file(FILE *const file, const sender sender);

void write_receiver_to_file(FILE *const file, const receiver receiver);

void write_coordinate_to_file(
    FILE *const file, const coordinate coordinate
);

void write_items_to_file(FILE *const file, const dllist_item *const list);

void write_item_to_file(FILE *const file, const item *const item);

#endif
