#include "uls.h"

t_file **insert_lstat(char **main_files, t_main *main) {
    for (int i = 0; i < main->str_size; i++) {
        free(main->files_struct[i]);
        main->files_struct[i] = get_lstat(main_files[i]);
    }
    main->files_struct[main->str_size] = NULL;
    return main->files_struct;
}
