#include "uuid_util.h"

char *uuid(char dest[UUID_STR_LEN]) {
    uuid_t buffer;
    uuid_generate(buffer);
    uuid_unparse_upper(buffer, dest);

    return dest;
}
