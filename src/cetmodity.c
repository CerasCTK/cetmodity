#include "cetmodity.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <uuid/uuid.h>

#include "auth.h"
#include "dllist_deliver.h"

dllist_deliver delivers;

void cetmodity_init() { dd_init(&delivers); }

void cetmodity_run() {
    char *found = login(delivers);

    if (strcmp(found, "-ADMIN-") == 0) {
        admin_menu();
    } else {
    }
}

void admin_menu() { printf("Admin menu"); }

void deliver_menu() { printf("Deliver menu"); }
