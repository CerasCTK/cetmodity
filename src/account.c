#include "account.h"

#include <string.h>

account create_account(const char *username, const char *password) {
    account new_account;

    strcpy(new_account.username, username);
    strcpy(new_account.password, password);

    return new_account;
}