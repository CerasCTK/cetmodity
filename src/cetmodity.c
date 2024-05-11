#include "cetmodity.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <uuid/uuid.h>

#include "dllist_deliver.h"
#include "dllist_order.h"
#include "menu.h"

dllist_deliver delivers;
dllist_order orders;

void cetmodity_init() {
    dd_init(&delivers);
    do_init(&orders);
}

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
        a_show_menu();
        printf("Input your option: ");
        scanf("%d", &opt);
        switch (opt) {
            case 1: admin_manage_delivers(); break;
            case 2: admin_manage_orders(); break;
            case 0: return logout();
            default:
                printf("Invalid choice, use only the options above\n");
                break;
        }
    }
}

void admin_manage_delivers() {
    int opt;
    bool loop = true;
    while (loop) {
        a_show_manage_delivers_menu();
        printf("Input your option: ");
        scanf("%d", &opt);
        switch (opt) {
            case 1: break;
            case 2: break;
            case 3: break;
            case 4: break;
            case 0: loop = false; break;
            default:
                printf("Invalid choice, use only the options above!\n");
                sleep(1);
                break;
        }
    }
}

void admin_manage_orders() {
    int opt;
    bool loop = true;
    while (loop) {
        a_show_manage_orders_menu();
        printf("Input your option: ");
        scanf("%d", &opt);
        switch (opt) {
            case 1: break;
            case 2: break;
            case 3: break;
            case 4: break;
            case 0: loop = false; break;
            default:
                printf("Invalid choice, use only the options above!\n");
                sleep(1);
                break;
        }
    }
}

void deliver_menu() { printf("Deliver menu"); }
