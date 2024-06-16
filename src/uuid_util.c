#include "uuid_util.h"

#include <stdlib.h>

void uuid(char dest[ID_LEN]) {
    char allowed_chars[]
        = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    for (int i = 0; i < ID_LEN - 1; i++) {
        if (i == 5)
            dest[i] = '-';
        else
            dest[i] = allowed_chars[rand() % (sizeof(allowed_chars) - 1)];
    }

    dest[ID_LEN - 1] = '\0';
}
