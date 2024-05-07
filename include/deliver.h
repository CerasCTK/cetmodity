#ifndef CETMODITY_DELIVER_H
#define CETMODITY_DELIVER_H

#include <uuid/uuid.h>

#include "account.h"
#include "define.h"
#include "dllist_order.h"

struct _deliver {
    char id[UUID_STR_LEN];
    char name[HUMAN_MAX_NAME_LEN];
    char phone_number[HUMAN_MAX_PHONE_LEN];
    account account;
    dllist_order orders;
};
typedef struct _deliver deliver;

bool is_same_deliver(deliver, deliver);

deliver create_deliver(char *, char *, const account);

#endif // !CETMODITY_DELIVER_H
