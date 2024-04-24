#ifndef CETMODITY_DELIVER_H
#define CETMODITY_DELIVER_H

#include "define.h"
#include "dllist_order.h"

struct _deliver {
    char name[HUMAN_MAX_NAME_LEN];
    char phone_number[HUMAN_MAX_PHONE_LEN];
    dllist_order orders;
};
typedef struct _deliver deliver;

#endif // !CETMODITY_DELIVER_H
