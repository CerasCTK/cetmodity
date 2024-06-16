#ifndef CETMODITY_ITEM_H
#define CETMODITY_ITEM_H

#include "bool.h"

#define PRODUCT_MAX_NAME_LEN 16

/**
 * @class item
 * @brief Struct of item
 *
 */
typedef struct item {
    char product_name[PRODUCT_MAX_NAME_LEN];
    unsigned int quantity;
    unsigned long unit_price;
} item;

/**
 * @brief Compare two items
 *
 * @param i1 First item to compare
 * @param i2 Second item to compare
 * @return true if the two items has the same product_name, false otherwise
 */
const bool is_same_item(const item *const i1, const item *const i2);

/**
 * @brief Create new item
 *
 * @param product_name Product name of the item
 * @param quantity Quanity of the item
 * @param unit_price Unit price of the item
 * @return New item with the given information
 */
item *const create_item(
    const char *product_name, const unsigned int quantity,
    const unsigned long unit_price
);

/**
 * @brief Create new item with input
 *
 * @return New item with the input information
 */
item *const create_item_input();

/**
 * @brief Get the length of the format below
 * Format of item info: `<product_name> - <quantity>\0`
 *
 * @param item Item to get the info length
 * @return Length of the format
 */
const int get_item_info_len(const item *const item);

/**
 * @brief Get the information of the item based on the format below
 * Format of item info: `<product_name> - <quantity>\0`
 *
 * @param item Item to get the information
 * @return Information of the item
 */
char *get_item_info_string(const item *const item);

#endif // !CETMODITY_ITEM_H
