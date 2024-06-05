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
    char name[RECEIVER_MAX_NAME_LEN];
    char phone_number[RECEIVER_MAX_PHONE_LEN];

    printf("Input information for new receiver:\n");
    printf("\t- Input receiver's name: ");
    input_string(name, RECEIVER_MAX_NAME_LEN);
    printf("\t- Input receiver's phone number: ");
    input_string(phone_number, RECEIVER_MAX_PHONE_LEN);

    coordinate location;
    printf("\t- Input receiver's location(lat, lon): ");
    scanf("%lf %lf", &location.latitude, &location.longitude);
    getchar();

    return create_receiver(name, phone_number, location);
}

void receiver_update_coor_input(receiver *receiver) {
    printf("Input new receiver's location(lat, long): ");
    scanf(
        "%lf %lf", &receiver->location.latitude, &receiver->location.longitude
    );
    getchar();
}
