#ifndef CETMODITY_SENDER_H
#define CETMODITY_SENDER_H

#include "coordinate.h"

#define SENDER_MAX_NAME_LEN 21
#define SENDER_MAX_PHONE_LEN 11

typedef struct sender {
    char name[SENDER_MAX_NAME_LEN];
    char phone_number[SENDER_MAX_PHONE_LEN];
    coordinate location;
} sender;

/**
 * @brief Create new sender
 *
 * @param name Name of the sender
 * @param phone_number Phone number of the sender
 * @param location Location of the sender
 * @return New sender with the given information
 */
sender
create_sender(const char *name, const char *phone_number, coordinate location);

/**
 * @brief Create new sender with input
 *
 * @return New sender with the input information
 */
sender create_sender_input();

#endif // !CETMODITY_SENDER_H
