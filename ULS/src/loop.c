#include "uls.h"

static bool check_symbol(char *print_name) {
    if (!mx_strcmp(print_name, ".") || !mx_strcmp(print_name, ".."))
        return false;
    return true;
}

static void print_dir(char *dir_name) {
    mx_printstr("\n");

    if (dir_name && dir_name[0] == '/' && dir_name[1] == '/' && dir_name[2] != '/')
        mx_printstr(&dir_name[1]);

    mx_printstr(dir_name);
    mx_printstr(":\n");
}

static void recursive(t_file **files, t_main *main) {
    char **memory = NULL;
    ino_t dev_fd = get_ino_dev_fd();

    for (int i = 0; files[i]; i++) {
        if (files[i]->type == 'd' && find_in_str(main->flags, 'R')) {
            if (find_in_str(main->flags, 'a')
                && !check_symbol(files[i]->print_name))
                continue;
            print_dir(files[i]->name);
            if (files[i]->ino == dev_fd)
                continue;
            memory = read_dir(files[i]->name, get_hidden(main->flags));
            if (!memory) {
                ls_error(ERR_EACCES, files[i]->print_name);
                continue;
            }
            loop(memory, main, false);
            mx_del_strarr(&memory);
        }
    }
}

void loop(char **files, t_main *main, bool print)
{
    main->files_count = get_arr_size(files);
    t_file **s_files = malloc_struct_array(main->files_count);

    for (int i = 0; files[i] ; i++)
    {
        free(s_files[i]);
        s_files[i] = get_lstat(files[i]);

        if (print)
            s_files[i]->print_name = s_files[i]->name;
    }

    run_sort(s_files, main->flags, main->files_count);
    ls_print(s_files, main);
    recursive(s_files, main);
    clean_struct(&s_files);
}
