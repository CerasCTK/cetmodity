#include "sender.h"
#include <string.h>

sender
create_sender(const char *name, const char *phone_number, coordinate location) {
    sender new_sender = { .location = location };
    strcpy(new_sender.name, name);
    strcpy(new_sender.phone_number, phone_number);

    return new_sender;
}
