#include "deliver.h"

#include <string.h>

bool is_same_deliver(deliver first, deliver second) {
    return strcmp(first.name, second.name);
}