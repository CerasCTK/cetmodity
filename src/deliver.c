#include "deliver.h"

#include <stdio.h>
#include <string.h>

#include "dllist_order.h"
#include "uuid_util.h"

bool is_same_deliver(const deliver d1, const deliver d2) {
    return strcmp(d1.id, d2.id) == 0;
}

deliver create_deliver(const char *name, const char *phone_number, const account account) {
    deliver new_deliver;
    uuid(new_deliver.id);
    strcpy(new_deliver.name, name);
    strcpy(new_deliver.phone_number, phone_number);
    strcpy(new_deliver.account.username, account.username);
    strcpy(new_deliver.account.password, account.password);

    do_init(&new_deliver.orders);
    return new_deliver;
}

void deliver_add_order(deliver *deliver, order new_order) {
    do_insert_end(&deliver->orders, new_order);
}