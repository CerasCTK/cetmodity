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
char *login(const dllist_deliver *const delivers);

/**
 * @brief Try to get deliver account by username and password
 *
 * @param delivers List contains all deliver
 * @param username Username of deliver
 * @param password Password of deliver
 * @return "-NONE-" if login failed, otherwise the deliver id or "-ADMIN-
 */
char *get_account(
    const dllist_deliver *const delivers, char username[USERNAME_MAX_LEN],
    char password[PASSWORD_MAX_LEN]
);

/**
 * @brief User logout function
 *
 * @return State of logout
 */
const logout_state logout();

#endif // !CETMODITY_AUTH_H
