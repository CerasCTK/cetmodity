#include "receiver.h"

#include "io_util.h"

#include <stdio.h>
#include <string.h>

receiver create_receiver(
    const char *name, const char *phone_number, const coordinate location
) {
    receiver new_receiver = { .location = location };
    strcpy(new_receiver.name, name);
    strcpy(new_receiver.phone_number, phone_number);

    return new_receiver;
}

receiver create_receiver_input() {
    char name[RECEIVER_MAX_NAME_LEN + 1];
    char phone_number[RECEIVER_MAX_PHONE_LEN + 1];

    printf("Input the receiver's name: ");
    input_string(name, RECEIVER_MAX_NAME_LEN + 1);
    printf("Input the receiver's phone number: ");
    input_string(phone_number, RECEIVER_MAX_PHONE_LEN + 1);

    coordinate location;
    printf("Input the receiver location: ");
    scanf("%lf %lf", &location.latitude, &location.longitude);

    return create_receiver(name, phone_number, location);
}
