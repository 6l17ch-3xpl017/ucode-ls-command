#include "uls.h"

void loop(char **files, t_main *main, bool print)
{
    main->files_count = get_arr_size(files);
    t_file **s_files = malloc_struct_array(main->files_count);

    for (int i = 0; files[i] ; i++)
    {
        free(s_files[i]);
        s_files[i] = get_lstat(files[i]);

        if (print)
            s_files[i]->print_name = s_files[i]->name;
    }

    run_sort(s_files, main->flags, main->files_count);


}