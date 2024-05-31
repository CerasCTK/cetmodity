#include "cetmodity_admin.h"

#include "deliver.h"
#include "dllist_deliver.h"
#include "io_util.h"

#include <stdio.h>
#include <string.h>

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