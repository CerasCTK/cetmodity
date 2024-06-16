#include "database.h"

#include "file_util.h"

#include <stdio.h>

const char *const DB_DELIVER_FILE = "delivers.txt";
const char *const DB_ORDER_FILE = "orders.txt";
const char *const DB_LINKER_FILE = "link.txt";

void load_database(dllist_deliver *const delivers, dllist_order *const orders) {
    if (!is_file_exist(DB_DELIVER_FILE)) {
        printf("Deliver file not found, cancel loading deliver list\n");
    } else {
        read_delivers_from_file(DB_DELIVER_FILE, delivers);
    }

    if (!is_file_exist(DB_ORDER_FILE)) {
        printf("Order file not found, cancel loading order list\n");
    } else {
        read_orders_from_file(DB_ORDER_FILE, orders);
    }

    if (!is_file_exist(DB_LINKER_FILE)) {
        printf("Linker file not found, cancel link list\n");
    } else {
        link_order_to_deliver_from_file(DB_LINKER_FILE, orders, delivers);
    }
}

void save_data_to_database(
    dllist_deliver *const delivers, dllist_order *const orders
) {
    write_delivers_to_file(DB_DELIVER_FILE, delivers);

    write_orders_to_file(DB_ORDER_FILE, orders);

    write_linker_to_file(DB_LINKER_FILE, orders);
}
