#ifndef CETMODITY_FILE_UTIL_H
#define CETMODITY_FILE_UTIL_H

#include "bool.h"
#include "coordinate.h"
#include "deliver.h"
#include "dllist_deliver.h"
#include "dllist_item.h"
#include "dllist_order.h"
#include "item.h"
#include "order.h"
#include "sender.h"

#include <stdio.h>

/**
 * @brief Check if the file is exist
 *
 * @param file_name File name to check
 * @return true if the file is exist, false otherwise
 */
bool is_file_exist(const char *const file_name);

/**
 * @brief Write list of deliver to file
 *
 * @param file_name File name to write
 * @param list List of deliver to write
 */
void write_delivers_to_file(
    const char *const file_name, const dllist_deliver *const list
);

/**
 * @brief Write deliver to file
 *
 * @param file File to write
 * @param deliver Deliver to write
 */
void write_deliver_to_file(FILE *const file, const deliver *const deliver);

/**
 * @brief Write account to file
 *
 * @param file File to write
 * @param account Account to write
 */
void write_account_to_file(FILE *const file, const account account);

/**
 * @brief Write list of order to file
 *
 * @param file_name File name to write
 * @param list List of order to write
 */
void write_orders_to_file(
    const char *const file_name, const dllist_order *const list
);

/**
 * @brief Write order to file
 *
 * @param file File to write
 * @param order Order to write
 */
void write_order_to_file(FILE *const file, const order *const order);

/**
 * @brief Write sender to file
 *
 * @param file File to write
 * @param sender Sender to write
 */
void write_sender_to_file(FILE *const file, const sender sender);

/**
 * @brief Write receiver to file
 *
 * @param file File to write
 * @param receiver Receiver to write
 */
void write_receiver_to_file(FILE *const file, const receiver receiver);

/**
 * @brief Write coordinate to file
 *
 * @param file File to write
 * @param coordinate Coordinate to write
 */
void write_coordinate_to_file(FILE *const file, const coordinate coordinate);

/**
 * @brief Write list of item to file
 *
 * @param file File to write
 * @param list List of item to write
 */
void write_items_to_file(FILE *const file, const dllist_item *const list);

/**
 * @brief Write item to file
 *
 * @param file File to write
 * @param item Item to write
 */
void write_item_to_file(FILE *const file, const item *const item);

/**
 * @brief Write the linker to file (order to deliver)
 *
 * @param file_name File name to write
 * @param list List of order to write
 */
void write_linker_to_file(
    const char *const file_name, const dllist_order *const list
);

/**
 * @brief Write number to the first line of the file
 *
 * @param file_name File name to write
 * @param number Number to write
 */
void append_number_to_first_line(const char *const file_name, const int number);

/**
 * @brief Read list of deliver from file to list parameter
 *
 * @param file_name File name to read
 * @param list List of deliver to store data
 */
void read_delivers_from_file(
    const char *const file_name, dllist_deliver *const list
);

/**
 * @brief Read deliver from file
 *
 * @param file File to read
 * @return Deliver read from file
 */
deliver *read_deliver_from_file(FILE *const file);

/**
 * @brief Read list of order from file to list parameter
 *
 * @param file_name File name to read
 * @param list List of order to store data
 */
void read_orders_from_file(
    const char *const file_name, dllist_order *const list
);

/**
 * @brief Read order from file
 *
 * @param file File to read
 * @return Order read from file
 */
order *read_order_from_file(FILE *const file);

/**
 * @brief Read list of item from file to list parameter
 *
 * @param file File to read
 * @param list List of item to store data
 */
void read_items_from_file(FILE *const file, dllist_item *const list);

/**
 * @brief Read item from file
 *
 * @param file File to read
 * @return Item read from file
 */
item *read_item_from_file(FILE *const file);

/**
 * @brief Link order to deliver from file
 *
 * @param file_name File name to read
 * @param orders List of order containing the order to be linked
 * @param delivers List of deliver containing the deliver to be linked
 */
void link_order_to_deliver_from_file(
    const char *const file_name, dllist_order *const orders,
    dllist_deliver *const delivers
);

#endif
