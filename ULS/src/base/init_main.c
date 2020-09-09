#include "uls.h"
#include "structures.h"

static bool check_color(char **flags, char *flag)
{
    if (linear_search(flag, flags))
        if (isatty(1) != 0)
        return true;
    return false;
}

t_main *mx_ls_create_main(int argc, char **argv) {
    t_main *main = malloc(sizeof(t_main));
    char *temp = init_flags(argv, argc);
    return main;
}