#include "cetmodity_admin.h"

#include "deliver.h"
#include "dllist_deliver.h"
#include <stdio.h>

void add_new_deliver(dllist_deliver *list) {
    const deliver new_deliver = create_deliver_input();
    dd_insert_end(list, new_deliver);
    printf("Create new deliver successfully\n");
}
