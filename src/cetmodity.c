#include "cetmodity.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <uuid/uuid.h>

#include "dllist_deliver.h"

dllist_deliver delivers;

void cetmodity_init() { dd_init(&delivers); }

void cetmodity_run() {
    char *found;
    logout_state state;
RELOGIN:
    found = login(delivers);

    if (strcmp(found, "-ADMIN-") == 0)
        state = admin_menu();
    else
        deliver_menu();

    if (state == LOGOUT_STATE)
        goto RELOGIN;
}

logout_state admin_menu() {
    int opt;
    while (true) {
        system("clear");
        show_admin_menu();
        printf("Input your option: ");
        scanf("%d", &opt);
        switch (opt) {
            case 1: printf("delivers\n"); break;
            case 2: printf("orders\n"); break;
            case 0: return logout();
            default:
                printf("Invalid choice, use only the options above\n");
                break;
        }
    }
}

void deliver_menu() { printf("Deliver menu"); }

void show_admin_menu() {
    printf("ADMIN MENU\n");
    printf("1. Manage delivers\n");
    printf("2. Manage orders\n");
    printf("0. Log out\n");
}
