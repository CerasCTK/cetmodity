#ifndef CETMODITY_RECEIVER_H
#define CETMODITY_RECEIVER_H

#include "define.h"

struct _receiver {
    char name[HUMAN_MAX_NAME_LEN];
    char phone_number[HUMAN_MAX_PHONE_LEN];
    char address[HUMAN_MAX_ADDRESS_LEN];
};
typedef struct _receiver receiver;

#endif // !CETMODITY_RECEIVER_H
