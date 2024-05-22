#ifndef CETMODITY_SENDER_H
#define CETMODITY_SENDER_H

#include "coordinate.h"

#define SENDER_MAX_NAME_LEN 20
#define SENDER_MAX_PHONE_LEN 10

typedef struct sender {
    char name[SENDER_MAX_NAME_LEN + 1];
    char phone_number[SENDER_MAX_PHONE_LEN + 1];
    coordinate location;
} sender;

sender create_sender(
    const char *name, const char *phone_number, coordinate location
);

sender create_sender_input();

#endif // !CETMODITY_SENDER_H
