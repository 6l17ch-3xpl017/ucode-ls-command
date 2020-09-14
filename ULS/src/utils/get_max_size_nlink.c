#include "uls.h"

int get_max_size_nlink(t_file **files) {
    unsigned int max_nlink = 0;

    for (int i = 0; files[i]; i++)
        if (files[i]->nlink > max_nlink)
            max_nlink = files[i]->nlink;
    return get_num_len(max_nlink);
}
