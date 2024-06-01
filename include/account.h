#ifndef CETMODITY_ACCOUNT_H
#define CETMODITY_ACCOUNT_H

#define USERNAME_MAX_LEN 11
#define PASSWORD_MAX_LEN 21

/**
 * @typedef account
 * @brief Account structure including username and password
 *
 */
typedef struct account {
    char username[USERNAME_MAX_LEN];
    char password[PASSWORD_MAX_LEN];
} account;

/**
 * @brief Create new account without input
 *
 * @param username Username of the account
 * @param password Passsword of the account
 * @return new account
 */
account create_account(const char *username, const char *password);

/**
 * @brief Create new account with user input
 *
 * @return new account
 */
account create_account_input();

#endif // !CETMODITY_ACCOUNT_H
