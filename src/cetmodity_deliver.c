#include "cetmodity_deliver.h"
#include "cetmodity_menu.h"

#include <stdio.h>

void complete_order(dllist_order *order_list, dllist_deliver *deliver_list) {
    order_node *node = do_search_by_id_input(*order_list);
    if (node == NULL) {
        printf("No order found with that ID!\n");
    }

    dllist_order order_list_of_deliver = dd_search_node_by_id(*deliver_list, node->order.deliver_id)->deliver.orders;
    order_node *order_of_deliver = do_search_by_id(order_list_of_deliver, node->order.id);

    if (order_of_deliver->order.status == delivered) {
        printf("Order has been delivered!\n");
        return;
    }

    node->order.status = delivered;
    order_of_deliver->order.status = delivered;

    printf("Completed order successfully!\n");
}