#include "account.h"

#include "io_util.h"

#include <stdio.h>
#include <string.h>

account create_account(const char *username, const char *password) {
    account new_account;

    strcpy(new_account.username, username);
    strcpy(new_account.password, password);

    return new_account;
}

account create_account_input() {
    char username[USERNAME_MAX_LEN + 1];
    char password[PASSWORD_MAX_LEN + 1];

    printf("Input username for account: ");
    input_string(username, USERNAME_MAX_LEN + 1);
    printf("Input password for account: ");
    input_string(password, PASSWORD_MAX_LEN + 1);

    return create_account(username, password);
}
