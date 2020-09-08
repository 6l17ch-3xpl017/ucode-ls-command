#include "uls.h"

//ToDo: Rename this method
char **malloc_array(size_t size) {
    char **array = malloc(size);

    for (int i = 0; i <= size; i++)
        array[i] = malloc(0); // ToDo: use lib func mx_strnew
    array[size] = NULL;

    return array;
}