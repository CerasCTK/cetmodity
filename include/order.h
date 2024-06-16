#ifndef CETMODITY_ORDER_H
#define CETMODITY_ORDER_H

#include "bool.h"
#include "dllist_item.h"
#include "receiver.h"
#include "sender.h"
#include "uuid_util.h"

#define SHIP_TAX 0.05
#define ORDER_STATUS_LENGTH 31

/**
 * @typedef order_status
 * @brief Status of the order.
 *
 */
typedef enum order_status { in_storage, in_transit, delivered } order_status;

/**
 * @typedef order
 * @brief Struct of order.
 *
 */
typedef struct order {
    char id[ID_LEN];

    char deliver_id[ID_LEN];

    sender sender;
    receiver receiver;

    dllist_item *item_list;

    unsigned long items_price;
    unsigned int shipping_fee;

    order_status status;
} order;

/**
 * @brief Compare two orders.
 *
 * @param o1 First order to compare.
 * @param o2 Second order to compare.
 * @return true if the two orders has the same id, false otherwise.
 */
const bool is_same_order(const order *const o1, const order *const o2);

/**
 * @brief Create new order with zero items.
 *
 * @param sender Sender of the order.
 * @param receiver Receiver of the order.
 * @return New order with the given information.
 */
order *const create_empty_order(const sender sender, const receiver receiver);

order *const create_empty_order_with_id(
    const char *const id, const sender sender, const receiver receiver
);

/**
 * @brief Add item to the order.
 *
 * @param order Order to add the item.
 * @param new_item New item to add.
 */
void order_add_item(order *const order, item *const new_item);

/**
 * @brief Add item to the order with input.
 *
 * @param order Order to add the item.
 */
void order_add_item_input(order *const order);

/**
 * @brief Show the information of the order.
 *
 * @param order Order to show the information.
 */
void show_order_information(const order *const order);

#endif // !CETMODITY_ORDER_H
