#ifndef CETMODITY_RECEIVER_H
#define CETMODITY_RECEIVER_H

#include "coordinate.h"

#define RECEIVER_MAX_NAME_LEN 21
#define RECEIVER_MAX_PHONE_LEN 11

typedef struct receiver {
    char name[RECEIVER_MAX_NAME_LEN];
    char phone_number[RECEIVER_MAX_PHONE_LEN];
    coordinate location;
} receiver;

receiver create_receiver(
    const char *name, const char *phone_number, coordinate location
);

receiver create_receiver_input();

void receiver_update_coor_input(receiver *receiver);

#endif // !CETMODITY_RECEIVER_H
