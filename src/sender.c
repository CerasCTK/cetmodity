#include "sender.h"

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
    sender new_sender;
    printf("Input the sender's name: ");
    scanf("%s", new_sender.name);
    printf("Input the sender's phone number: ");
    scanf("%s", new_sender.phone_number);
    printf("Input the sender's location: ");
    scanf(
        "%lf %lf", &new_sender.location.latitude, &new_sender.location.longitude
    );
    return new_sender;
}
