#include "uls.h"

/**
 * Function initialize flags to one string of flags
 * @param argv arguments from main
 * @param argc quantity of arguments
 * @return string of flags in argv
 */
char *init_flags(int argc, char **argv)
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