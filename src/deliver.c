#include "deliver.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dllist_order.h"
#include "io_util.h"
#include "uuid_util.h"

const bool is_same_deliver(const deliver *const d1, const deliver *const d2) {
    return strcmp(d1->id, d2->id) == 0;
}

deliver *const create_deliver(
    const char *const name, const char *const phone_number,
    const account account
) {
    deliver *new_deliver = malloc(sizeof(deliver));

    if (new_deliver == NULL) {
        printf("Memory not allocated\n");
        return NULL;
    }

    uuid(new_deliver->id);
    strcpy(new_deliver->name, name);
    strcpy(new_deliver->phone_number, phone_number);
    strcpy(new_deliver->account.username, account.username);
    strcpy(new_deliver->account.password, account.password);

    do_init(&new_deliver->orders);
    return new_deliver;
}

deliver *const create_deliver_input() {
    char name[DELIVER_MAX_NAME_LEN];
    char phone_number[DELIVER_MAX_PHONE_LEN];

    printf("Input information for new deliver:\n");
    printf("\t- Input deliver's name: ");
    input_string(name, DELIVER_MAX_NAME_LEN);
    printf("\t- Input deliver's phone number: ");
    input_string(phone_number, DELIVER_MAX_PHONE_LEN);

    return create_deliver(name, phone_number, create_account_input());
}

void change_deliver_information_input(deliver *const deliver) {
    printf("Change the deliver's information:\n");
    printf("\t- Input deliver's name: ");
    input_string(deliver->name, DELIVER_MAX_PHONE_LEN);
    printf("\t- Input deliver's phone number: ");
    input_string(deliver->phone_number, DELIVER_MAX_PHONE_LEN);

    printf("Change deliver information successfully!\n");
}

void show_deliver_information(const deliver *const deliver) {
    printf("\t- Deliver's name: %s\n", deliver->name);
    printf("\t- Deliver's phone number: %s\n", deliver->phone_number);
    printf("\t- Deliver's account: %s\n", deliver->account.username);
}

void deliver_add_order(const deliver *const deliver, order *const new_order) {
    do_insert(deliver->orders, new_order);
}
