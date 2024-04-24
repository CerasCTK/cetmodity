#ifndef CETMODITY_ORDER_H
#define CETMODITY_ORDER_H

#include "dllist_item.h"
#include "receiver.h"
#include "sender.h"

#include <uuid/uuid.h>

enum _order_status { IN_TRANSIT, DELIVERED };
typedef enum _order_status order_status;

struct _order {
    char id[UUID_STR_LEN];
    sender sender;
    receiver receiver;
    dllist_item items;
    long total_price;
};
typedef struct _order order;

#endif // !CETMODITY_ORDER_H
