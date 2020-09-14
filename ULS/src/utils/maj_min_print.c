#include "uls.h"

void maj_min_print(t_file *files) {
    char *major = mx_itoa((int)files->file_major);
    char *minor = mx_itoa((int)files->file_minor);

    print_format_str(major, 'r', ' ', 5);
    mx_printstr(",");
    print_format_str(minor, 'r', ' ', 4);
    mx_printstr(" ");
    mx_strdel(&major);
    mx_strdel(&minor);
}
