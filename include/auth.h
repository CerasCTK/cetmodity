#ifndef CETMODITY_AUTH_H
#define CETMODITY_AUTH_H

#include "account.h"
#include "dllist_deliver.h"

enum _logout_state { EXIT_STATE, LOGOUT_STATE };
typedef enum _logout_state logout_state;

char *login(const dllist_deliver);

char *get_account(
    const dllist_deliver, char[USERNAME_MAX_LEN],
    char[PASSWORD_MAX_LEN]
);

logout_state logout();

#endif // !CETMODITY_AUTH_H
