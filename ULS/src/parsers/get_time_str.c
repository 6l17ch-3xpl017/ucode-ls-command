#include "uls.h"

char *get_time_str(t_file *file, t_ls_l_data *print_struct) {
    char *str = NULL;
    char *temp = ctime(&file->mtime);

    if (!print_struct->st) {
        if (print_struct->cur_time - file->mtime > 15552000)
            str = mx_strjoin(mx_strndup(&temp[4], 7), mx_strndup(&temp[19], 5));
        else
            str = mx_strndup(&temp[4], 12);
    }
    else
        str = mx_strndup(&temp[4], 20);
    return str;
}
