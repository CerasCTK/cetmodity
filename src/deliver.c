#include "deliver.h"

#include <string.h>

bool is_same_deliver(deliver first, deliver second) {
    return strcmp(first.phone_number, second.phone_number) == 0;
}
