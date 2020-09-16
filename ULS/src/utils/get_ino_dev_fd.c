#include "uls.h"

ino_t get_ino_dev_fd(void) {
    struct stat buf;

    lstat("/dev/fd", &buf);
    return buf.st_ino;
}