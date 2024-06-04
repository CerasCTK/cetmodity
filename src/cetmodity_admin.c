#include "cetmodity_admin.h"

#include "deliver.h"
#include "dllist_deliver.h"
#include "receiver.h"

#include <stdio.h>
#include <string.h>
#include <table.h>

// Deliver manage
void add_new_deliver(dllist_deliver *list) {
    const deliver new_deliver = create_deliver_input();
    bool is_success = dd_insert_end(list, new_deliver);

    if (is_success)
        printf("Create new deliver successfully\n");
    else
        printf("Something wrong when create new deliver\n");
}

void display_deliver_information(dllist_deliver list) {
    if (dd_is_empty(list)) {
        printf("No deliver found!");
        return;
    }

    deliver_node *node = dd_search_node_by_id_input(list);

    if (node == NULL) {
        printf("No deliver found with that ID!\n");
        return;
    }

    show_deliver_information(node->deliver);

    printf("Enter to go back\n");
    getchar();
}

void edit_deliver_information(dllist_deliver *list) {
    if (dd_is_empty(*list)) {
        printf("No deliver to change!\n");
        return;
    }

    deliver_node *node = dd_search_node_by_id_input(*list);

    if (node == NULL) {
        printf("No deliver found with that ID!\n");
        return;
    }

    show_deliver_information(node->deliver);

    deliver_information_change_input(&node->deliver);
}

void delete_deliver(dllist_deliver *list) {
    if (dd_is_empty(*list)) {
        printf("No deliver to delete!\n");
        return;
    }

    deliver_node *node = dd_search_node_by_id_input(*list);

    if (node == NULL) {
        printf("No deliver found with that ID!\n");
        return;
    }

    show_deliver_information(node->deliver);

    int opt;
    printf("Do you want to delete this deliver?\n");
    printf("\t1. Yes\n");
    printf("\t2. No\n");
    printf("Input your option: ");
    scanf("%d", &opt);
    getchar();

    if (opt == 1) {
        bool is_success = dd_delete(list, node);
        if (is_success)
            printf("Delete successfully\n");
        else
            printf("Something error on delete\n");
    } else
        printf("Cancelled delete\n");
}

// Order manage
void add_new_order(dllist_order *list) {
    sender sender = create_sender_input();
    receiver receiver = create_receiver_input();

    order order = create_empty_order(sender, receiver);

    while (true) {
        printf("Input item for the order:\n");
        order_add_item_input(&order);

        printf("Do you want to input new item?\n");
        printf("\t1. Yes\n");
        printf("\t2. No\n");
        printf("Input your choice: ");

        int choice = 0;
        scanf("%d", &choice);
        getchar();

        if (choice == 2)
            break;
    }

    bool is_success = do_insert_end(list, order);

    if (is_success) {
        printf("Create new order successfully!\n");
    } else {
        printf("Something wrong when create new order!\n");
    }
}

void display_order_information(dllist_order list) {
    if (do_is_empty(list)) {
        printf("No deliver found!");
        return;
    }

    order_node *node = do_search_by_id_input(list);

    if (node == NULL) {
        printf("No order found with that ID!\n");
        return;
    }

    show_order_information(node->order);

    printf("Enter to go back\n");
    getchar();
}

void edit_order_information(dllist_order *list) {
    if (do_is_empty(*list)) {
        printf("No order to change!\n");
        return;
    }

    order_node *order_node = do_search_by_id_input(*list);

    if (order_node == NULL) {
        printf("No order found!\n");
        return;
    }

    show_order_detail(order_node->order);

    receiver_update_coor_input(&(order_node->order.receiver));

    printf("Update successfully");
}

void delete_order(dllist_order *list) {
    if (do_is_empty(*list)) {
        printf("No order to delete!\n");
        return;
    }

    order_node *node = do_search_by_id_input(*list);

    if (node == NULL) {
        printf("No order found!\n");
        return;
    }

    show_order_detail(node->order);

    int opt;
    printf("Do you want to delete this order?\n");
    printf("\t1. Yes\n");
    printf("\t2. No\n");
    printf("Input your option: ");
    scanf("%d", &opt);
    getchar();

    if (opt == 1) {
        do_delete(list, node);
        printf("Delete successfully\n");
    } else {
        printf("Cancelled delete\n");
    }
}
