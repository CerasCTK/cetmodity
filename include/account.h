#ifndef CETMODITY_ACCOUNT_H
#define CETMODITY_ACCOUNT_H

#define USERNAME_MAX_LEN 10
#define PASSWORD_MAX_LEN 20

struct _account {
    char username[10];
    char password[20];
};
typedef struct _account account;

#endif // !CETMODITY_ACCOUNT_H
