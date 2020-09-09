#include "uls.h"

char *init_flags(char **argv, int argc)
{
    char *flags = NULL;
    char *temp = NULL;

    for (int i = 1; i < argc && argv[i][0] == '-'; i++)
    {
        if (flags)
            temp = mx_strdup(flags);

        mx_strdel(&flags);
        flags = mx_strjoin(temp, &argv[i][1]);
        mx_strdel(&temp);
    }

    return flags;
}