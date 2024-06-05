#ifndef CETMODITY_CETMODITY_H
#define CETMODITY_CETMODITY_H

#include "auth.h"

/**
 * @brief Initial cetmodity application
 */
void cetmodity_init();

/**
 * @brief Run loop for cetmodity application
 */
void cetmodity_run();

/**
 * @brief Menu for admin
 *
 * @return State of logout
 */
logout_state admin_menu();

void deliver_menu();

/**
 * @brief Menu for admin to manage delivers
 */
void admin_manage_delivers();

/**
 * @brief Menu for admin to manage orders
 */
void admin_manage_orders();

#endif // !CETMODITY_CETMODITY_H
