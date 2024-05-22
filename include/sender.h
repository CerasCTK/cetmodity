#ifndef CETMODITY_SENDER_H
#define CETMODITY_SENDER_H

#include "coordinate.h"

#define SENDER_MAX_NAME_LEN 20
#define SENDER_MAX_PHONE_LEN 10

struct _sender {
    char name[SENDER_MAX_NAME_LEN + 1];
    char phone_number[SENDER_MAX_PHONE_LEN + 1];
    coordinate location;
};
typedef struct _sender sender;

sender create_sender(
    const char *name, const char *phone_number, const coordinate location
);

sender create_sender_input();

#endif // !CETMODITY_SENDER_H
