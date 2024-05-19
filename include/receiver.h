#ifndef CETMODITY_RECEIVER_H
#define CETMODITY_RECEIVER_H

#include "coordinate.h"
#include "define.h"

struct _receiver {
    char name[HUMAN_MAX_NAME_LEN];
    char phone_number[HUMAN_MAX_PHONE_LEN];
    coordinate location;
};
typedef struct _receiver receiver;

receiver create_receiver(
    const char *name, const char *phone_number, const coordinate location
);

receiver create_receiver_input();

#endif // !CETMODITY_RECEIVER_H
