#ifndef CETMODITY_AUTH_H
#define CETMODITY_AUTH_H

#include "account.h"
#include "dllist_deliver.h"

typedef enum logout_state { cetmodity_exit, cetmodity_logout } logout_state;

char *login(dllist_deliver delivers);

char *get_account(
    dllist_deliver delivers, char username[USERNAME_MAX_LEN],
    char password[PASSWORD_MAX_LEN]
);

logout_state logout();

#endif // !CETMODITY_AUTH_H
