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

void a_show_menu() {
    SLEEP;
    CLRSCR;
    PRINTNL("Admin main menu:");
    PRINTNL("\t1. Manage delivers");
    PRINTNL("\t2. Manage orders");
    PRINTNL("\t0. Log out");
}

void a_show_manage_delivers_menu(const dllist_deliver delivers) {
    SLEEP;
    CLRSCR;
    show_deliver_table(delivers);
    PRINTNL("Admin manage delivers menu:");
    PRINTNL("\t1. Add new deliver");
    PRINTNL("\t2. Edit deliver infomation");
    PRINTNL("\t3. Delete deliver");
    PRINTNL("\t4. Show list of delivers");
    PRINTNL("\t0. Go back");
}

void a_show_manage_orders_menu(const dllist_order orders) {
    SLEEP;
    CLRSCR;
    show_order_table_for_manager(orders);
    PRINTNL("Admin manage orders menu:");
    PRINTNL("\t1. Add new order");
    PRINTNL("\t2. Edit the exist order");
    PRINTNL("\t3. Delete order");
    PRINTNL("\t4. Show list of orders");
    PRINTNL("\t0. Go back");
}
