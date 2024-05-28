#include "sender.h"

#include "io_util.h"

#include <stdio.h>
#include <string.h>

sender create_sender(
    const char *name, const char *phone_number, const coordinate location
) {
    sender new_sender = { .location = location };
    strcpy(new_sender.name, name);
    strcpy(new_sender.phone_number, phone_number);

    return new_sender;
}

sender create_sender_input() {
    char name[SENDER_MAX_NAME_LEN + 1];
    char phone_number[SENDER_MAX_PHONE_LEN + 1];

    printf("Input the sender's name: ");
    input_string(name, SENDER_MAX_NAME_LEN + 1);
    printf("Input the sender's phone number: ");
    input_string(phone_number, SENDER_MAX_PHONE_LEN + 1);

    coordinate location;
    printf("Input the sender's location: ");
    scanf("%lf %lf", &location.latitude, &location.longitude);

    return create_sender(name, phone_number, location);
}
