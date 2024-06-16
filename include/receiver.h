#ifndef CETMODITY_RECEIVER_H
#define CETMODITY_RECEIVER_H

#include "coordinate.h"

#define RECEIVER_MAX_NAME_LEN 21
#define RECEIVER_MAX_PHONE_LEN 11

typedef struct receiver {
    char name[RECEIVER_MAX_NAME_LEN];
    char phone_number[RECEIVER_MAX_PHONE_LEN];
    coordinate location;
} receiver;

/**
 * @brief Create new receiver
 *
 * @param name Name of the receiver
 * @param phone_number Phone number of the receiver
 * @param location Location of the receiver
 * @return New receiver with the given information
 */
receiver create_receiver(
    const char *name, const char *phone_number, coordinate location
);

/**
 * @brief Create new receiver with input
 *
 * @return New receiver with the input information
 */
receiver create_receiver_input();

/**
 * @brief Update the location of the receiver with input
 *
 * @param receiver Receiver to update the location
 */
void receiver_update_coor_input(receiver *receiver);

#endif // !CETMODITY_RECEIVER_H
