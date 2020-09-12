#include "uls.h"

t_file **malloc_struct_array(int size)
{
    t_file **head = malloc(sizeof(t_file*) * (size + 1));

    for (int i = 0; i < size; i++)
        head[i] = malloc(sizeof(t_file));

    head[size] = NULL;
    return head;
}