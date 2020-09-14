#include "uls.h"

int find_max_length_gid(t_file **files) {
    int max_len = mx_strlen(files[0]->gid_name);
    int len;

    for (int i = 1; files[i]; i++)
        (len = mx_strlen(files[i]->gid_name)) > max_len ? max_len = len : 0;

    return max_len;
}
