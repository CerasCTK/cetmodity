#include "cetmodity_admin.h"

#include "deliver.h"
#include "dllist_deliver.h"
#include "io_util.h"

#include <stdio.h>
#include <string.h>
#include <table.h>

// Deliver manage
void add_new_deliver(dllist_deliver *list) {
    const deliver new_deliver = create_deliver_input();
    dd_insert_end(list, new_deliver);
    printf("Create new deliver successfully\n");
}

void edit_deliver_information(dllist_deliver *list) {
    if (dd_is_empty(*list)) {
        printf("No deliver to change!\n");
        return;
    }

    char name[DELIVER_MAX_NAME_LEN + 1];
    char phone_number[DELIVER_MAX_PHONE_LEN + 1];

    deliver_node *node = dd_search_node_by_id_input(*list);

    if (node == NULL) {
        printf("No deliver found!\n");
        return;
    }

    show_deliver_information(node->deliver);

    printf("\nChange deliver information");
    printf("\nInput deliver's name: ");
    input_string(name, DELIVER_MAX_PHONE_LEN);
    printf("Input deliver's phone number: ");
    input_string(phone_number, DELIVER_MAX_PHONE_LEN);

    strcpy(node->deliver.name, name);
    strcpy(node->deliver.phone_number, phone_number);
}

void delete_deliver(dllist_deliver *list) {
    if (dd_is_empty(*list)) {
        printf("No deliver to delete!\n");
        return;
    }

    deliver_node *node = dd_search_node_by_id_input(*list);

    if (node == NULL) {
        printf("No deliver found!\n");
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
        dd_delete(list, node);
        printf("Delete successfully\n");
    } else {
        printf("Cancelled delete\n");
    }
}

// Order manage
void add_new_order(dllist_order *list) {
    sender sender = create_sender_input();
    receiver receiver = create_receiver_input();

    order order = create_empty_order(sender, receiver);

    bool loop = true;
    while (loop) {
        printf("Input item for the order:\n");
        order_add_item_input(&order);

        printf("Do you want to input new item?\n");
        printf("\t1. Yes\n");
        printf("\t2. No\n");
        printf("Input your choice: ");

        int choice = 0;
        scanf("%d", &choice);
        getchar();

        if (choice == 2) loop = false;
    }

    do_insert_end(list, order);
}

void delete_order(dllist_order *list) {
    if (do_is_empty(*list)) {
        printf("No order to delete!\n");
        return;
    }

    order_node *node = do_search_by_id_input(list);

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