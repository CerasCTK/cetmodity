#include "uuid_util.h"

char *uuid(char out[UUID_STR_LEN]) {
    uuid_t buffer;
    uuid_generate(buffer);
    uuid_unparse_upper(buffer, out);

    return out;
}
