#ifndef CETMODITY_CETMODITY_H
#define CETMODITY_CETMODITY_H

#include "auth.h"

void cetmodity_init();

void cetmodity_run();

auth_state admin_menu();

void deliver_menu();

void admin_manage_delivers();

void admin_manage_orders();

#endif // !CETMODITY_CETMODITY_H
