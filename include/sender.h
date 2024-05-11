#ifndef CETMODITY_SENDER_H
#define CETMODITY_SENDER_H

#include "coordinate.h"
#include "define.h"

struct _sender {
    char name[HUMAN_MAX_NAME_LEN];
    char phone_number[HUMAN_MAX_PHONE_LEN];
    coordinate location;
};
typedef struct _sender sender;

sender create_sender(const char *, const char *, const coordinate);

sender create_sender_input();

#endif // !CETMODITY_SENDER_H
