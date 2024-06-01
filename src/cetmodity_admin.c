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

        if (choice == 2)
            loop = false;
    }

    do_insert_end(list, order);
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

    int opt;
    printf("Do you want to change coordinate or list item?\n");
    printf("\t1. Coordinate\n");
    printf("\t2. List item\n");
    printf("Input your option: ");
    scanf("%d", &opt);
    getchar();

    if (opt == 1) {
        double latitude, longitude;
        printf("Input receiver's coordinate to change: ");
        scanf("%lf %lf", &latitude, &longitude);
        getchar();

        order_node->order.receiver.location.latitude = latitude;
        order_node->order.receiver.location.longitude = longitude;

    } else if (opt == 2) {
        item_node *item_node
            = di_search_node_by_name_input(order_node->order.items);

        if (item_node == NULL) {
            printf("No item found!\n");
            return;
        }

        int opt_item;

        printf("Do you want change quantity or delete item?\n");
        printf("\t1. Change quantity item\n");
        printf("\t2. Delete item\n");
        printf("Input your option: ");
        scanf("%d", &opt_item);
        getchar();

        if (opt_item == 1) {
            unsigned int quantity;
            printf("Input quantity item to change: ");
            scanf("%u", &quantity);
            getchar();

            item_node->item.quantity = quantity;

            printf("Successfully!\n");
        } else if (opt_item == 2) {
            di_delete(&order_node->order.items, item_node);
            printf("Delete successfully!\n");
        } else {
            printf("Canceled!\n");
        }

    } else {
        printf("Canceled!\n");
    }
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
