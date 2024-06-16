#include "cetmodity_deliver.h"
#include "time_util.h"

#include <stdio.h>

void complete_order(const deliver *const deliver) {
    order_node *node = do_search_by_id_input(deliver->orders);

    if (node == NULL) {
        printf("No order found with that ID!\n");
        return;
    }

    node->order->status = delivered;
    get_time_string(node->order->delivered_at);

    printf("Completed order successfully!\n");
}
