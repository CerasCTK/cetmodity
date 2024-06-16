#include "file_util.h"

#include <unistd.h>

bool is_file_exist(const char *const file_name) {
    return access(file_name, F_OK) == 0;
}
