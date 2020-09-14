#include "uls.h"

static void print_sym(char sym, int number)
{
    for (int i = 0; i < number; i++)
        mx_printchar(sym);
}

void print_format_str(char *str, char local, char sym, int size)
{
    int len = mx_strlen(str);

    if (local == 'c')
        print_sym(sym, (size - len) / 2);
    if (local == 'r')
        print_sym(sym, size - len);

    mx_printstr(str);

    if (local == 'c')
        print_sym(sym, size - len - (size - len) / 2);

    if (local == 'l')
        print_sym(sym, size - len);
}

void print_format_l(t_file *file, t_main *main, int size) {
    int len = mx_strlen(file->print_name);
    char name = 'l';

    if (name == 'c')
        print_sym(' ', (size - len) / 2);
    if (name == 'r')
        print_sym(' ', size - len);

    print_color(file, main->color);

    if (name == 'c')
        print_sym(' ', size - len - (size - len) / 2);
    if (name == 'l')
        print_sym(' ', size - len);
}
