#include "uls.h"

int get_max_file_size(t_file **files) {
    long long int max_size = 0;

    for (int i = 0; files[i]; i++)
        if (files[i]->size > max_size)
            max_size = files[i]->size;
    return get_num_len(max_size);
}
