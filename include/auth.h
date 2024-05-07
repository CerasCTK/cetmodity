#ifndef CETMODITY_AUTH_H
#define CETMODITY_AUTH_H

#include "account.h"
#include "dllist_deliver.h"

char *login(const dllist_deliver);

char *get_account(
    const dllist_deliver, char[USERNAME_MAX_LEN],
    char[PASSWORD_MAX_LEN]
);

#endif // !CETMODITY_AUTH_H
