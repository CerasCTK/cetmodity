#include "receiver.h"
#include <string.h>

receiver create_receiver(
    const char *name, const char *phone_number, coordinate location
) {
    receiver new_receiver = { .location = location };
    strcpy(new_receiver.name, name);
    strcpy(new_receiver.phone_number, phone_number);

    return new_receiver;
}
