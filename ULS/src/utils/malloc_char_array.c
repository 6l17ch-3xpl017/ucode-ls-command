#include "uls.h"

//ToDo: Rename this method
char **malloc_char_array(size_t size) {
    char **array = malloc(sizeof(char *) * (size + 1));

    for (size_t i = 0; i <= size; i++)
        array[i] = NULL;

    return array;
}