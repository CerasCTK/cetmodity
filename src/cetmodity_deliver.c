#include "cetmodity_deliver.h"

#include <stdio.h>

void complete_order(deliver *const deliver) {
    order_node *node = do_search_by_id_input(deliver->orders);
    if (node == NULL) {
        printf("No order found with that ID!\n");
        return;
    }

    node->order->status = delivered;

    printf("Completed order successfully!\n");
}
