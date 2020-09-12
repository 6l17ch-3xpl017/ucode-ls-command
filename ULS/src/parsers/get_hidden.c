#include "uls.h"

int get_hidden(char *flags)
{
    if (find_in_str(flags, 'a'))
        return 1;
    else if (find_in_str(flags, 'A'))
        return 2;
    return 0;
}
