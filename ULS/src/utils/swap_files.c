#include "uls.h"

void swap_files(t_file **file1, t_file **file2)
{
    t_file *temp;

    temp = *file1;
    *file1 = *file2;
    *file2 = temp;
}