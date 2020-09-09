#include "uls.h"

void check_args(int argc, char **argv)
{
    struct stat stat_buf;

    for (int i = 1; i != argc; i++)
        if (argv[i][0] != '-' && stat(argv[i], &stat_buf) != 0)
            printf("uls: %s: %s", argv[i], strerror(errno));
}