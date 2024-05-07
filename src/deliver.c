#include "deliver.h"
#include "dllist_order.h"

#include <string.h>

bool is_same_deliver(deliver first, deliver second) {
    return strcmp(first.phone_number, second.phone_number) == 0;
}

deliver create_deliver(char *name, char *phone_number, account account) {
    deliver new_deliver = { .account = account };
    strcpy(new_deliver.name, name);
    strcpy(new_deliver.phone_number, phone_number);

    do_init(&new_deliver.orders);
    return new_deliver;
}
