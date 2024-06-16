#ifndef CETMODITY_DATABASE_H
#define CETMODITY_DATABASE_H

#include "dllist_deliver.h"
#include "dllist_order.h"

/**
 * @brief Load data from database
 *
 * @param delivers Deliver list to store data
 * @param orders Order list to store data
 */
void load_database(dllist_deliver *const delivers, dllist_order *const orders);

/**
 * @brief Save data to database
 *
 * @param delivers Deliver list to save data
 * @param orders Order list to save data
 */
void save_data_to_database(
    dllist_deliver *const delivers, dllist_order *const orders
);

#endif // !CETMODITY_DATABASE_H
