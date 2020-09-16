#include "uls.h"
#include "structures.h"

static char *add_flag(int argc, char **argv)
{
    char *temp_flags = init_flags(argc, argv);
    char *flags = NULL;
    char *str = mx_strjoin(LS_VALID_STR_ONE, LS_VALID_STR_TWO);

    validate_flags(str, LS_FUNC_NAME, temp_flags, LS_VALID_FLAGS);
    flags = clear_flags(temp_flags, LS_CLEAR_STR);
    mx_strdel(&temp_flags);
    mx_strdel(&str);

    return flags;
}

t_main *init_main(int argc, char **argv) {
    t_main *main = malloc(sizeof(t_main));
    char **files = init_files(argc, argv);
    int files_count = get_arr_size(files);
    char *flags = add_flag(argc, argv);

    main->files = files;
    main->files_struct = malloc_struct_array(files_count);
    main->flags = flags;
    main->color = find_in_str(flags, 'G') ? isatty(1) ? true : false : false;
    main->str_size = files_count;
    main->files_count = files_count;
    main->terminal_width = get_term_width();
    main->is_term = isatty(1) ? true : false;

    return main;
}