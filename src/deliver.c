#include "deliver.h"

#include <stdio.h>
#include <string.h>

#include "dllist_order.h"
#include "io_util.h"
#include "uuid_util.h"

bool is_same_deliver(const deliver d1, const deliver d2) {
    return strcmp(d1.id, d2.id) == 0;
}

deliver create_deliver(
    const char *name, const char *phone_number, const account account
) {
    deliver new_deliver;

    uuid(new_deliver.id);
    strcpy(new_deliver.name, name);
    strcpy(new_deliver.phone_number, phone_number);
    strcpy(new_deliver.account.username, account.username);
    strcpy(new_deliver.account.password, account.password);

    do_init(&new_deliver.orders);
    return new_deliver;
}

deliver create_deliver_input() {
    char name[DELIVER_MAX_NAME_LEN + 1];
    char phone_number[DELIVER_MAX_PHONE_LEN + 1];

    printf("Input the deliver's name: ");
    input_string(name, DELIVER_MAX_NAME_LEN + 1);
    printf("Input the deliver's phone name: ");
    input_string(phone_number, DELIVER_MAX_PHONE_LEN + 1);

    return create_deliver(name, phone_number, create_account_input());
}

void deliver_add_order(deliver *deliver, const order new_order) {
    do_insert_end(&deliver->orders, new_order);
}
