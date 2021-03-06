#include "uls.h"

static int size_consol(void) {
	struct winsize window;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &window);	
    return window.ws_col;
}

static void print_d_name(char *dir) {
    mx_printstr(dir);
    mx_printstr(":\n");
}

void print_with_commas_format(data_t ****data, flags_t *flag, largest_t ***largest, start_t *start_data, format_t *format) {
    bool print_dir_name = false;
    bool need_new_line = false;
    int consol_size = size_consol();

    if (!format->print_in_terminal)
        consol_size = 79;
    if (start_data->no_fd_num > 0) {
        print_no_fd(start_data);
    }
    if (start_data->files_num > 0) {
        print_dir_name = true;
        for (int i = 0; i < start_data->files_num; i++) {
            print_with_coma_string(data[0][i], flag, largest[0][0], consol_size);
            if (i + 1 != start_data->files_num)
                mx_printstr(", ");
            else
                if (start_data->dirs_num > 0)
                    mx_printstr(", ");
        }
        mx_printchar('\n');
    }
    if (start_data->dirs_num > 0) {
        if (print_dir_name == true)
            need_new_line = true;
        for (int i = 0; i < start_data->dirs_num; i++) {
            if (need_new_line == true)
                mx_printchar('\n');  
            if (print_dir_name == true || start_data->dirs_num > 1)
                print_d_name(start_data->dirs[i]);
            if (largest[1][i]->quantity > 0) {
                print_with_coma_string(data[1][i], flag, largest[1][i], consol_size);
                mx_printchar('\n');
            }
            need_new_line = true;
        }
    }
}
