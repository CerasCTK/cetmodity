#include "order.h"

#include <string.h>

bool is_same_order(order first, order second) {
    return strcmp(first.id, second.id) == 0;
}
