#include "uls.h"

bool check_character_files(t_file **files)
{
    for (int i = 0; files[i]; i++)
        if (files[i]->type == 'c' || files[i]->type == 'b')
            return true;

    return false;
}
