#ifndef CETMODITY_ACCOUNT_H
#define CETMODITY_ACCOUNT_H

#define USERNAME_MAX_LEN 10
#define PASSWORD_MAX_LEN 20

typedef struct account {
    char username[10];
    char password[20];
} account;

account create_account(const char *username, const char *password);

#endif // !CETMODITY_ACCOUNT_H
