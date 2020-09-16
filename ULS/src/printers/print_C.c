#include "uls.h"

static int get_max_len(t_file **files) {
    int max_len = 0;

    if (files)
        for (int i = 0; files[i] != NULL; i++)
            if (mx_strlen(files[i]->print_name) > max_len)
                max_len = mx_strlen(files[i]->print_name);

    return max_len;
}

void print_big_c(t_file **files, t_main *main) {
    int row = 8 * (get_max_len(files) / 8) + 8;
    int cols = main->terminal_width / row;
    int rows;

    if (!cols)
        cols++;

    rows = main->files_count / cols;
    if (main->files_count % cols != 0)
        rows++;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (main->files_count - 1 == j * rows + i)
                print_color(files[j * rows + i], main->color);
            if (main->files_count - 1 > j * rows + i)
                print_format_l(files[j * rows + i], main, row);
        }
        mx_printchar('\n');
    }
}