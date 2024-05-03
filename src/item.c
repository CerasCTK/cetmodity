#include "item.h"

#include <string.h>

bool is_same_item(item first, item second) {
    return strcmp(first.product_name, second.product_name) == 0;
}
