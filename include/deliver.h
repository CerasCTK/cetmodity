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
    dllist_order *orders;
} deliver;

const bool is_same_deliver(const deliver *const d1, const deliver *const d2);

deliver *const
create_deliver(const char *name, const char *phone_number, account account);

deliver *const create_deliver_input();

void change_deliver_information_input(deliver *const deliver);

void show_deliver_information(const deliver *const deliver);

void deliver_add_order(const deliver *const deliver, order *const new_order);

#endif // !CETMODITY_DELIVER_H
