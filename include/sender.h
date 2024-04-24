#ifndef CETMODITY_SENDER_H
#define CETMODITY_SENDER_H

#include "define.h"
#include "dllist_item.h"

struct _sender {
    char name[HUMAN_MAX_NAME_LEN];
    char phone_number[HUMAN_MAX_PHONE_LEN];
    char address[HUMAN_MAX_ADDRESS_LEN];
    dllist_item items;
};
typedef struct _sender sender;

#endif // !CETMODITY_SENDER_H
