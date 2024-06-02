#ifndef CETMODITY_DELIVER_H
#define CETMODITY_DELIVER_H

#include "account.h"
#include "dllist_order.h"
#include "uuid_util.h"

#define DELIVER_MAX_NAME_LEN 21
#define DELIVER_MAX_PHONE_LEN 11

typedef struct deliver {
    char id[ID_LEN];
    char name[DELIVER_MAX_NAME_LEN];
    char phone_number[DELIVER_MAX_PHONE_LEN];
    account account;
    dllist_order orders;
} deliver;

bool is_same_deliver(deliver d1, deliver d2);

deliver
create_deliver(const char *name, const char *phone_number, account account);

deliver create_deliver_input();

void deliver_information_change_input(deliver *deliver);

void show_deliver_information(deliver deliver);

void deliver_add_order(deliver *deliver, order new_order);

#endif // !CETMODITY_DELIVER_H
