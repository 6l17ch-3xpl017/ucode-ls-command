#include "uls.h"

char *get_rights_str(int file_mode)
{
    char *result = mx_strdup("---------");
    int rights[9] = {S_IRUSR, S_IWUSR, S_IXUSR, S_IRGRP, S_IWGRP, S_IXGRP, S_IROTH, S_IWOTH, S_IXOTH};
    char rights_letters[9] = {'r', 'w', 'x', 'r', 'w', 'x', 'r', 'w', 'x'};

    for (int i = 0; i < 9; i++)
        if (rights[i] == (rights[i] & file_mode))
            result[i] = rights_letters[i];

    return result;
}
