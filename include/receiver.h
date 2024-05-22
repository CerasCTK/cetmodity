#ifndef CETMODITY_RECEIVER_H
#define CETMODITY_RECEIVER_H

#include "coordinate.h"

#define RECEIVER_MAX_NAME_LEN 20
#define RECEIVER_MAX_PHONE_LEN 10

typedef struct receiver {
    char name[RECEIVER_MAX_NAME_LEN + 1];
    char phone_number[RECEIVER_MAX_PHONE_LEN + 1];
    coordinate location;
} receiver;

receiver create_receiver(
    const char *name, const char *phone_number, const coordinate location
);

receiver create_receiver_input();

#endif // !CETMODITY_RECEIVER_H
