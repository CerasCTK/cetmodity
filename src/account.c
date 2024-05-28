#include "account.h"

#include <io_util.h>
#include <string.h>
#include <stdio.h>

account create_account(const char *username, const char *password) {
    account new_account;

    strcpy(new_account.username, username);
    strcpy(new_account.password, password);

    return new_account;
}

account create_account_input() {
    char username[USERNAME_MAX_LEN];
    char password[PASSWORD_MAX_LEN];

    printf("Input username for account: ");
    input_string(username, USERNAME_MAX_LEN);
    printf("Input password for account: ");
    input_string(password, PASSWORD_MAX_LEN);

    return create_account(username, password);
}