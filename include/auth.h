#ifndef CETMODITY_AUTH_H
#define CETMODITY_AUTH_H

#include "account.h"
#include "dllist_deliver.h"

/**
 * @typedef logout_state
 * @brief State of logout
 *
 */
typedef enum logout_state { cetmodity_exit, cetmodity_logout } logout_state;

/**
 * @brief User login function
 *
 * @param delivers Deliver list
 * @return "-NONE-" if login failed, otherwise the deliver id or "-ADMIN-"
 */
char *login(dllist_deliver delivers);

/**
 * @brief Try to get deliver account by username and password
 *
 * @param delivers List contains all deliver
 * @param username Username of deliver
 * @param password Password of deliver
 * @return "-NONE-" if login failed, otherwise the deliver id or "-ADMIN-
 */
char *get_account(
    dllist_deliver delivers, char username[USERNAME_MAX_LEN + 1],
    char password[PASSWORD_MAX_LEN + 1]
);

/**
 * @brief User logout function
 *
 * @return State of logout
 */
logout_state logout();

#endif // !CETMODITY_AUTH_H
