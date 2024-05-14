#include "account.h"

#include <string.h>

account create_account(char *username, char *password) {
    account new_account;

    strcpy(new_account.username, username);
    strcpy(new_account.password, password);

    return new_account;
}