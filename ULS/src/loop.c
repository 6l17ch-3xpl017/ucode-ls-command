#include "uls.h"

void loop(char **files, t_main *main, bool print)
{
    main->file_n = get_arr_size(files);
    t_file **s_files = malloc_struct_array(main->file_n);

    for (int i = 0; files[i] ; i++)
    {
        free(s_files[i]);
        s_files[i] =
    }

}