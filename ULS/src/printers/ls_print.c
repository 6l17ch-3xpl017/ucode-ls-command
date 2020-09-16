#include "uls.h"

static void print_one(t_file **files, t_main *main) {
    for (int i = 0; i != main->files_count; i++) {
        print_color(files[i], main->color);
        mx_printstr("\n");
    }
}

static void print_m(t_file **files, t_main *main) {
    int len = 0;

    for (int i = 0; i != main->files_count; i++) {
        if (i != 0 && len != 0){
            mx_printstr(" ");
            len += mx_strlen(" ");
        }
        len += mx_strlen(files[i]->name) ;
        print_color(files[i], main->color);
        if (i != main->files_count -1)
            mx_printstr(",");
        if (len >= main->terminal_width) {
            mx_printstr("\n");
            len = 0;
        }
        if (i == main->files_count - 1)
            mx_printstr("\n");
    }
}

void ls_print(t_file **files, t_main *main)
{
    char *flags = main->flags;

    if (find_in_str(flags, 'l'))
        print_l(files, main);
    else if (find_in_str(flags, '1'))
        print_one(files, main);
    else if (find_in_str(flags, 'm'))
        print_m(files, main);
    else if (main->is_term == false)
        if (find_in_str(flags, 'C'))
            print_C(files, main);
        else
            print_one(files, main);
    else
        print_C(files, main);
}
