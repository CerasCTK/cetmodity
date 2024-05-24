#ifndef CETMODITY_ACCOUNT_H
#define CETMODITY_ACCOUNT_H

#define USERNAME_MAX_LEN 10
#define PASSWORD_MAX_LEN 20

/**
 * @typedef account
 * @brief Account structure including username and password
 *
 */
typedef struct account {
    char username[USERNAME_MAX_LEN + 1];
    char password[PASSWORD_MAX_LEN + 1];
} account;

/**
 * @brief Create new account
 *
 * @param username Username of the account
 * @param password Passsword of the account
 * @return new account
 */
account create_account(const char *username, const char *password);

#endif // !CETMODITY_ACCOUNT_H
