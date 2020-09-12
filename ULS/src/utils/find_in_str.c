#include "uls.h"

bool find_in_str(const char *string, char sought)
{
    if (mx_get_char_index(string, sought) >= 0)
        return true;
    return false;
}