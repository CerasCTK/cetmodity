#include "database.h"

#include "file_util.h"

#include <stdio.h>

const char *const DATABASE_FILE_NAME = "cetmodity.dat";

void load_database(dllist_deliver *const delivers, dllist_order *const orders) {
    if (!is_file_exist(DATABASE_FILE_NAME)) {
        printf("Database file not found, cancel loading database\n");
        return;
    }
}

void stop_database() {}
