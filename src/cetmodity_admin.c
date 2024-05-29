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
    char name[DELIVER_MAX_NAME_LEN + 1];
    char phone_number[DELIVER_MAX_PHONE_LEN + 1];
    char id[UUID_STR_LEN + 1];

    printf("Input deliver's ID to edit: ");
    input_string(id, UUID_STR_LEN);

    deliver_node *node = dd_search_node_by_id(*list, id);

    if (node == NULL) {
        printf("No deliver found!\n");
        return;
    }
    else {
        printf("Deliver's name: %s", node->deliver.name);
        printf("Deliver's phone name: %s", node->deliver.phone_number);
    }

    printf("\nChange deliver information");
    printf("\nInput deliver's name: ");
    input_string(name, DELIVER_MAX_PHONE_LEN);
    printf("Input deliver's phone number: ");
    input_string(phone_number, DELIVER_MAX_PHONE_LEN);

    strcpy(node->deliver.name, name);
    strcpy(node->deliver.phone_number, phone_number);
}
