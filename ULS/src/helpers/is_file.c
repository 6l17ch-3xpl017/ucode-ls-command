#include "uls.h"

bool is_file(char *filename) {
    struct stat buf;
    stat(filename, &buf);

    return ((((buf.st_mode)) & 0170000) == (0100000));
}