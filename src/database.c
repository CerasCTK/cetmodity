#include "database.h"

#include "file_util.h"

#include <stdio.h>

const char *const DB_DELIVER_FILE = "delivers.txt";
const char *const DB_ORDER_FILE = "orders.txt";
const char *const DB_LINK_FILE = "link.txt";

void load_database(dllist_deliver *const delivers, dllist_order *const orders) {
    if (!is_file_exist(DB_DELIVER_FILE)) {
        printf("Deliver file not found, cancel loading deliver list\n");
    }
    if (!is_file_exist(DB_DELIVER_FILE)) {
        printf("Deliver file not found, cancel loading deliver list\n");
    }
    if (!is_file_exist(DB_DELIVER_FILE)) {
        printf("Deliver file not found, cancel loading deliver list\n");
    }
}

void save_data_to_database(
    dllist_deliver *const delivers, dllist_order *const orders
) {
    write_delivers_to_file(DB_DELIVER_FILE, delivers);
    write_orders_to_file(DB_ORDER_FILE, orders);
}
