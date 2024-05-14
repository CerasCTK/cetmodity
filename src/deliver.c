#include "deliver.h"

#include <string.h>

#include "dllist_order.h"
#include "uuid_util.h"

bool is_same_deliver(deliver first, deliver second) {
    return strcmp(first.id, second.id) == 0;
}

deliver create_deliver(char *name, char *phone_number, account account) {
    deliver new_deliver;
    uuid(new_deliver.id);
    strcpy(new_deliver.name, name);
    strcpy(new_deliver.phone_number, phone_number);
    strcpy(new_deliver.account.username, account.username);
    strcpy(new_deliver.account.password, account.password);

    do_init(&new_deliver.orders);
    return new_deliver;
}
