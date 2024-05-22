#ifndef CETMODITY_DELIVER_H
#define CETMODITY_DELIVER_H

#include <uuid/uuid.h>

#include "account.h"
#include "dllist_order.h"

#define DELIVER_MAX_NAME_LEN 20
#define DELIVER_MAX_PHONE_LEN 10

typedef struct deliver {
    char id[UUID_STR_LEN];
    char name[DELIVER_MAX_NAME_LEN + 1];
    char phone_number[DELIVER_MAX_PHONE_LEN + 1];
    account account;
    dllist_order orders;
} deliver;

bool is_same_deliver(deliver d1, deliver d2);

deliver create_deliver(char *name, char *phone_number, const account account);

#endif // !CETMODITY_DELIVER_H
