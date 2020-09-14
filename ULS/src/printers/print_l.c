#include "uls.h"

static void print_total(t_file **files, int file_n) {
    long long int total = 0;
    char *print_total = NULL;

    if (*files != NULL) {
        mx_printstr("total ");
        for (int i = 0; i < file_n; i++)
            total += files[i]->blocks;

        print_total = mx_itoa(total);
        mx_printstr(print_total);
        mx_strdel(&print_total);
        mx_printchar('\n');
    }
}

static void print_link(t_file *files, int max_nlink_len) {
    char *link= mx_itoa((int)files->nlink);
    print_format_str(link, 'r', ' ', max_nlink_len);
    mx_printstr(" ");
    mx_strdel(&link);
}

static void print_size(t_file *files, int max_size_len) {
    char *size = mx_itoa((int)files->size);
    mx_printstr("  ");
    print_format_str(size, 'r', ' ', max_size_len);
    mx_printstr(" ");
    mx_strdel(&size);
}

static void print_l_more(t_file *file, t_ls_l_data *print_struct)
{
    mx_printchar(file->type);
    print_rights(file);

    if (get_xattr(file->name))
        mx_printstr("@ ");

    else if (file->acl_inf)
        mx_printstr("+ ");

    else
        mx_printstr("  ");

    print_link(file, print_struct->max_link);
    print_format_str(file->uid_name, 'l', ' ', print_struct->max_uid);
    mx_printstr("  ");
    print_format_str(file->gid_name, 'l', ' ', print_struct->max_gid);

    if (file->type != 'c' || file->type == 'b')
    {
        if (!print_struct->character_files)
            print_size(file, print_struct->max_size);
        else
            print_size(file, 8 + print_struct->max_size);
    }
    else
        maj_min_print(file);
}

void print_l(t_file **files, t_main *main)
{
    t_ls_l_data *print_struct = init_ls_data(files, main);
    char *time_str = NULL;
    char *temp = NULL;

    if (print_struct->check_dir)
        print_total(files, main->files_count);

    for (int i = 0; i < main->files_count i++) {
        print_l_more(files[i], print_struct);
        temp = ctime(&files[i]->mtime);
        time_str = get_time_str(files[i], print_struct);
        mx_printstr(time_str);
        mx_printstr(" ");
        print_color(files[i], main->color);
        if (files[i]->type == 'l')
            print_link_name(files[i]->name);
        mx_printstr("\n");
        mx_strdel(&time_str);
    }
}