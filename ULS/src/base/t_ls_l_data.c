#include "uls.h"

t_ls_l_data *init_ls_data(t_file **files, t_main *main) {
    t_ls_l_data *res = malloc(sizeof(t_ls_l_data));

    res->st = find_in_str(main->flags, 'T');
    res->max_uid = find_max_length_uid(files);
    res->max_gid = find_max_length_gid(files);
    res->character_files = check_character_files(files);
    res->max_size = get_max_file_size(files);
    res->cur_time = time(NULL);
    res->max_link = get_max_size_nlink(files);
    res->check_dir = false;

    for (int i = 0; files[i]; i++)
        if (files[i]->type == 'd' || mx_strcmp(files[i]->name, files[i]->print_name)) {
            res->check_dir = true;
            break;
        }
    return res;
}
