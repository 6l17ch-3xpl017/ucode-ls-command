#include "uls.h"

void print_rights(t_file *files) {
    char *rights_str = get_rights_str(files->mode);

    mx_printstr(rights_str);
    mx_strdel(&rights_str);
}
