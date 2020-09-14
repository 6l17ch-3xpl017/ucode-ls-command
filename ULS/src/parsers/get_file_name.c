#include "uls.h"

char *get_name(const char *file)
{
    for (int i = mx_strlen(file) - 1; i != 0; i--)
        if (file[i] == '/')
            return (char *)&file[i + 1];
    return (char *)file;
}