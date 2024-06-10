#ifndef CETMODITY_DELIVER_H
#define CETMODITY_DELIVER_H

#include "account.h"
#include "dllist_order.h"
#include "uuid_util.h"

#define DELIVER_MAX_NAME_LEN 21
#define DELIVER_MAX_PHONE_LEN 11

/**
 * @typedef deliver
 * @brief Struct of deliver
 *
 */
typedef struct deliver {
    char id[ID_LEN];
    char name[DELIVER_MAX_NAME_LEN];
    char phone_number[DELIVER_MAX_PHONE_LEN];
    account account;
    dllist_order *orders;
} deliver;

/**
 * @brief Compare two delivers
 *
 * @param d1 First deliver to compare
 * @param d2 Second deliver to compare
 * @return true if two delivers has the same id, false otherwise
 */
const bool is_same_deliver(const deliver *const d1, const deliver *const d2);

/**
 * @brief Create new deliver
 *
 * @param name Name of the deliver
 * @param phone_number Phone number of the deliver
 * @param account Account of the deliver
 * @return New deliver with the given information
 */
deliver *const create_deliver(
    const char *const name, const char *const phone_number,
    const account account
);

/**
 * @brief Create new deliver with input
 *
 * @return New deliver with the input information
 */
deliver *const create_deliver_input();

/**
 * @brief Change deliver information
 *
 * @param deliver Deliver to change information
 */
void change_deliver_information_input(deliver *const deliver);

/**
 * @brief Show deliver information
 *
 * @param deliver Deliver to show information
 */
void show_deliver_information(const deliver *const deliver);

/**
 * @brief Add order to order list of deliver
 *
 * @param deliver Deliver to add order
 * @param new_order Order to add
 */
void deliver_add_order(const deliver *const deliver, order *const new_order);

#endif // !CETMODITY_DELIVER_H
