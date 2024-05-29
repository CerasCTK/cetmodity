#include "cetmodity.h"

#include <stdio.h>
#include <string.h>

#include "auth.h"
#include "cetmodity_admin.h"
#include "cetmodity_menu.h"
#include "dllist_deliver.h"
#include "dllist_order.h"

dllist_deliver delivers;
dllist_order orders;

void cetmodity_init() {
    dd_init(&delivers);
    do_init(&orders);
}

void cetmodity_run() {
    char *found;
    logout_state state = cetmodity_exit;

RELOGIN:
    found = login(delivers);
    if (strcmp(found, "-ADMIN-") == 0) {
        printf("Login successfully as admin\n");
        state = admin_menu();
    } else {
        printf("Login successfully as deliver\n");
        deliver_menu();
    }

    if (state == cetmodity_logout)
        goto RELOGIN;

    dd_free(&delivers);
    do_free(&orders);
}

logout_state admin_menu() {
    int opt;
    while (true) {
        a_show_menu();
        printf("Input your option: ");
        scanf("%d", &opt);
        getchar();
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
        a_show_manage_delivers_menu(delivers);
        printf("Input your option: ");
        scanf("%d", &opt);
        getchar();
        switch (opt) {
            case 1: add_new_deliver(&delivers); break;
            case 2: edit_deliver_information(&delivers);break;
            case 3: break;
            case 0: loop = false; break;
            default:
                printf("Invalid choice, use only the options above!\n");
                break;
        }
    }
}

void admin_manage_orders() {
    int opt;
    bool loop = true;
    while (loop) {
        a_show_manage_orders_menu(orders);
        printf("Input your option: ");
        scanf("%d", &opt);
        getchar();
        switch (opt) {
            case 1: break;
            case 2: break;
            case 3: break;
            case 0: loop = false; break;
            default:
                printf("Invalid choice, use only the options above!\n");
                break;
        }
    }
}

void deliver_menu() { printf("Deliver menu"); }
