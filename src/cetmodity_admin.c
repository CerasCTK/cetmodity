#include "cetmodity_admin.h"

#include "cetmodity_menu.h"
#include "deliver.h"
#include "dllist_deliver.h"
#include "io_util.h"
#include "receiver.h"

#include <stdio.h>
#include <string.h>
#include <table.h>

#define SEPERATE_LINE                                                          \
    (printf("-----------------------------------------------\n"))

// Deliver manage
void add_new_deliver(dllist_deliver *const list) {
    SEPERATE_LINE;
    deliver *new_deliver = create_deliver_input();

    bool is_success = dd_insert(list, new_deliver);

    if (is_success)
        printf("Create new deliver successfully\n");
    else
        printf("Something wrong when create new deliver\n");
}

void display_deliver_information(const dllist_deliver *const list) {
    if (dd_is_empty(list)) {
        printf("Deliver list is empty, nothing to show!\n");
        return;
    }

    SEPERATE_LINE;
    deliver_node *node = dd_search_node_by_id_input(list);

    if (node == NULL) {
        printf("No deliver found with that ID!\n");
        return;
    }

    show_deliver_information(node->deliver);

    print_message_bottom_left("--Press Enter to go back--");
    wait_for_enter();
}

void edit_deliver_information(const dllist_deliver *const list) {
    if (dd_is_empty(list)) {
        printf("Deliver list is empty, nothing to edit!\n");
        return;
    }

    SEPERATE_LINE;
    deliver_node *node = dd_search_node_by_id_input(list);

    if (node == NULL) {
        printf("No deliver found with that ID!\n");
        return;
    }

    show_deliver_information(node->deliver);

    SEPERATE_LINE;
    change_deliver_information_input(node->deliver);
}

void delete_deliver(dllist_deliver *const list) {
    if (dd_is_empty(list)) {
        printf("Deliver list is empty, nothing to delete!\n");
        return;
    }

    SEPERATE_LINE;
    deliver_node *node = dd_search_node_by_id_input(list);

    if (node == NULL) {
        printf("No deliver found with that ID!\n");
        return;
    }

    show_deliver_information(node->deliver);

    SEPERATE_LINE;
    int confirm_delete = confirm_menu("Do you want to delete this deliver?");

    if (confirm_delete) {
        bool is_success = dd_delete(list, node);
        if (is_success)
            printf("Delete successfully\n");
        else
            printf("Something error on delete\n");
    } else
        printf("Cancelled delete\n");
}

// Order manage
void add_new_order(dllist_order *const list) {
    sender sender = create_sender_input();
    receiver receiver = create_receiver_input();

    order *order = create_empty_order(sender, receiver);

    while (true) {
        SEPERATE_LINE;
        printf("Input item for the order:\n");
        order_add_item_input(order);

        bool continue_input = confirm_menu("Do you want to input new item?");

        if (!continue_input)
            break;
    }

    bool is_success = do_insert(list, order);

    if (is_success) {
        printf("Create new order successfully!\n");
    } else {
        printf("Something wrong when create new order!\n");
    }
}

void display_order_information(const dllist_order *const list) {
    if (do_is_empty(list)) {
        printf("No deliver found!");
        return;
    }

    SEPERATE_LINE;
    order_node *node = do_search_by_id_input(list);

    if (node == NULL) {
        printf("No order found with that ID!\n");
        return;
    }

    show_order_information(node->order);

    print_message_bottom_left("--Press Enter to go back--");
    wait_for_enter();
}

void edit_order_information(const dllist_order *const list) {
    if (do_is_empty(list)) {
        printf("No order to change!\n");
        return;
    }

    SEPERATE_LINE;
    order_node *order_node = do_search_by_id_input(list);

    if (order_node == NULL) {
        printf("No order found!\n");
        return;
    }

    show_order_detail(order_node->order);

    receiver_update_coor_input(&(order_node->order->receiver));

    printf("Update successfully\n");
}

void delete_order(dllist_order *const list) {
    if (do_is_empty(list)) {
        printf("No order to delete!\n");
        return;
    }

    SEPERATE_LINE;
    order_node *node = do_search_by_id_input(list);

    if (node == NULL) {
        printf("No order found with that ID!\n");
        return;
    }

    show_order_detail(node->order);

    const bool confirm_delete
        = confirm_menu("Do you want to delete this order?");

    if (confirm_delete) {
        do_delete(list, node);
        printf("Delete successfully!\n");
    } else {
        printf("Cancelled delete!\n");
    }
}

void distribute_order_to_deliver(
    dllist_order *list_order, dllist_deliver *list_deliver
) {
    if (do_is_empty(list_order)) {
        printf("Order list is empty, nothing to ship!\n");
        return;
    }

    if (dd_is_empty(list_deliver)) {
        printf("Deliver list is empty, nothing to ship!\n");
        return;
    }

    SEPERATE_LINE;
    order_node *order_node = do_search_by_id_input(list_order);
    if (order_node == NULL) {
        printf("No order found with that ID!\n");
        return;
    }
    if (order_node->order->status == 1 || order_node->order->status == 2) {
        printf("Order has been delivered!\n");
        return;
    }

    deliver_node *deliver_node = dd_search_node_by_id_input(list_deliver);
    if (deliver_node == NULL) {
        printf("No deliver found with that ID!\n");
        return;
    }

    order_node->order->status = in_transit;
    strcpy(order_node->order->deliver_id, deliver_node->deliver->id);
    do_insert(deliver_node->deliver->orders, order_node->order);

    printf("Distribute order successfully!\n");
}
