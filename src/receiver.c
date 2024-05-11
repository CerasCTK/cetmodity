#include "receiver.h"
#include <stdio.h>
#include <string.h>

receiver create_receiver(
    const char *name, const char *phone_number, coordinate location
) {
    receiver new_receiver = { .location = location };
    strcpy(new_receiver.name, name);
    strcpy(new_receiver.phone_number, phone_number);

    return new_receiver;
}

receiver create_receiver_input() {
    receiver new_receiver;

    printf("Input the receiver's name: ");
    scanf("%s", new_receiver.name);
    printf("Input the receiver's phone number: ");
    scanf("%s", new_receiver.phone_number);
    printf("Input the receiver location: ");
    scanf(
        "%lf %lf", &new_receiver.location.latitude,
        &new_receiver.location.longitude
    );

    return new_receiver;
}
