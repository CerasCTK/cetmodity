#ifndef CETMODITY_LLIST_ITEM_H
#define CETMODITY_LLIST_ITEM_H

#include "bool.h"
#include "item.h"

/**
 * @class item_node
 * @brief Struct of a node in the linked list of item.
 *
 */
typedef struct item_node {
    item *item;
    struct item_node *next, *prev;
} item_node;

/**
 * @class dllist_item
 * @brief Struct of doubly linked list of items.
 *
 */
typedef struct dllist_item {
    item_node *head;
    item_node *tail;
} dllist_item;

/**
 * @brief Initialize a doubly linked list of items.
 *
 * @param list List to be initialized.
 */
void di_init(dllist_item *const list);

/**
 * @brief Check if the list is empty.
 *
 * @param list List to be checked.
 * @return true if the list is empty, false otherwise.
 */
const bool di_is_empty(const dllist_item *const list);

/**
 * @brief Check if the item is in the list.
 *
 * @param list List to be checked.
 * @param item Item to be checked.
 * @return true if the item is in the list, false otherwise.
 */
const bool di_is_in_list(const dllist_item *const list, const item *const item);

/**
 * @brief Get the size of the list.
 *
 * @param list List to get the size.
 * @return Size of the list.
 */
const int di_size(const dllist_item *const list);

/**
 * @brief Insert an item with product_name not exist in list to the end of the
 * list.
 *
 * @param list List where store the item.
 * @param item Item to be inserted.
 */
void di_insert(dllist_item *const list, item *const item);

/**
 * @brief Get the item by index.
 *
 * @param list List to get the item.
 * @param index Index of the item.
 * @return item_node* if the index is valid, NULL otherwise.
 */
item_node *const di_get_by_index(const dllist_item *const list, int index);

/**
 * @brief Search the item by product name.
 *
 * @param list List to get the item.
 * @param item_name Product name of the item.
 * @return item_node* if the item is found, NULL otherwise.
 */
item_node *const di_search_node_by_product_name(
    const dllist_item *const list, const char *item_name
);

/**
 * @brief Search the item by product name get from input.
 *
 * @param list List to get the item.
 * @return item_node* if the item is found, NULL otherwise.
 */
item_node *di_search_node_by_product_name_input(const dllist_item *const list);

/**
 * @brief Delete an item from the list.
 *
 * @param list List has the item to be deleted.
 * @param node Node of the item.
 */
void di_delete(dllist_item *const list, item_node *const node);

/**
 * @brief Calculate the total price of the list.
 *
 * @param list List to calculate the total price.
 */
const unsigned long di_calculate_total_price(const dllist_item *const list);

/**
 * @brief Free the memory of the list.
 *
 * @param list List to be free.
 */
void di_free(dllist_item *const list);

#endif // !CETMODITY_LLIST_ITEM_H
