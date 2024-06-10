#include "cetmodity_menu.h"

#include "table.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define CLRSCR (system("clear"))
#define PRINTNL(msg)                                                           \
    {                                                                          \
        printf(msg);                                                           \
        printf("\n");                                                          \
    }
#define SECOND 1000
#define SLEEP (usleep(500 * SECOND))

void logout_menu() {
    SLEEP;
    CLRSCR;
    PRINTNL("Do you want to exit or logout?");
    PRINTNL("\t1. Logout");
    PRINTNL("\t2. Exit");
}

const bool confirm_menu(const char *const msg) {
    int opt;
    printf("%s\n", msg);
    PRINTNL("\t1. Yes");
    PRINTNL("\t2. No");
    printf("Input your option: ");
    scanf("%d", &opt);

    getchar();

    return opt == 1 ? true : false;
}

void admin_manage_menu() {
    SLEEP;
    CLRSCR;
    PRINTNL("Admin main menu:");
    PRINTNL("\t1. Manage delivers");
    PRINTNL("\t2. Manage orders");
    PRINTNL("\t0. Log out");
}

void admin_manage_delivers_menu(const dllist_deliver *const delivers) {
    SLEEP;
    CLRSCR;
    show_deliver_table(delivers);
    PRINTNL("Admin manage delivers menu:");
    PRINTNL("\t1. Add new deliver");
    PRINTNL("\t2. Show deliver information");
    PRINTNL("\t3. Edit deliver infomation");
    PRINTNL("\t4. Delete deliver");
    PRINTNL("\t0. Go back");
}

void admin_manage_orders_menu(
    const dllist_order *const orders, const dllist_deliver *const delivers
) {
    SLEEP;
    CLRSCR;
    show_order_table_for_manager(orders, delivers);
    PRINTNL("Admin manage orders menu:");
    PRINTNL("\t1. Add new order");
    PRINTNL("\t2. Show order information");
    PRINTNL("\t3. Edit order information");
    PRINTNL("\t4. Delete order");
    PRINTNL("\t5. Distribute orders to deliver");
    PRINTNL("\t0. Go back");
}

void deliver_manage_menu(const deliver *const deliver) {
    SLEEP;
    CLRSCR;
    show_order_table_for_deliver(deliver);
    PRINTNL("Deliver manage orders menu:");
    PRINTNL("\t1. Finish the order");
    PRINTNL("\t0. Logout");
}
