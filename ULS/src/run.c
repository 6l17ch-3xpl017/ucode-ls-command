#include "uls.h"

void run(t_main *main)
{
    char **rem = NULL;

    if (!main->files_count)
    {
        rem = read_dir(".", get_hidden(main->flags));
        loop(rem, main, false);
        mx_del_strarr(&rem);
    }
}
