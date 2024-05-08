#include "menu.h"

#include <stdio.h>
#include <stdlib.h>

#define CLRSCR (system("clear"))
#define printnl(msg)                                                           \
    {                                                                          \
        printf(msg);                                                           \
        printf("\n");                                                          \
    }

void a_show_menu() {
    CLRSCR;
    printnl("Admin main menu:");
    printnl("\t1. Manage delivers");
    printnl("\t2. Manage orders");
    printnl("\t0. Log out");
}

void a_show_manage_delivers_menu() {
    CLRSCR;
    printnl("Admin manage delivers menu:");
    printnl("\t1. Add new deliver");
    printnl("\t2. Edit deliver infomation");
    printnl("\t3. Delete deliver");
    printnl("\t4. Show list of delivers");
    printnl("\t0. Go back");
}
