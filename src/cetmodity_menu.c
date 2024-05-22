#include "cetmodity_menu.h"

#include <stdio.h>
#include <stdlib.h>

#define CLRSCR (system("clear"))
#define PRINTNL(msg)                                                           \
    {                                                                          \
        printf(msg);                                                           \
        printf("\n");                                                          \
    }

void a_show_menu() {
    CLRSCR;
    PRINTNL("Admin main menu:");
    PRINTNL("\t1. Manage delivers");
    PRINTNL("\t2. Manage orders");
    PRINTNL("\t0. Log out");
}

void a_show_manage_delivers_menu() {
    CLRSCR;
    PRINTNL("Admin manage delivers menu:");
    PRINTNL("\t1. Add new deliver");
    PRINTNL("\t2. Edit deliver infomation");
    PRINTNL("\t3. Delete deliver");
    PRINTNL("\t4. Show list of delivers");
    PRINTNL("\t0. Go back");
}

void a_show_manage_orders_menu() {
    CLRSCR;
    PRINTNL("Admin manage orders menu:");
    PRINTNL("\t1. Add new order");
    PRINTNL("\t2. Edit the exist order");
    PRINTNL("\t3. Delete order");
    PRINTNL("\t4. Show list of orders");
    PRINTNL("\t0. Go back");
}
