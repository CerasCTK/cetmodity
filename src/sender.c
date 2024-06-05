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
    char name[SENDER_MAX_NAME_LEN];
    char phone_number[SENDER_MAX_PHONE_LEN];

    printf("-------------------------------------------------------------------"
           "--\n");
    printf("Input information for new sender:\n");
    printf("\t- Input sender's name: ");
    input_string(name, SENDER_MAX_NAME_LEN);
    printf("\t- Input sender's phone number: ");
    input_string(phone_number, SENDER_MAX_PHONE_LEN);

    coordinate location;
    printf("\t- Input sender's location(lat, long): ");
    scanf("%lf %lf", &location.latitude, &location.longitude);
    getchar();

    return create_sender(name, phone_number, location);
}
