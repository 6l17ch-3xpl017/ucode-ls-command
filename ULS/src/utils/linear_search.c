#include "uls.h"

bool linear_search(char *word, char **array)
{
    int result;

    for (int i = 0; array[i] && (result = strcmp(word, array[i])) != 0; i++);

    return result == 0;
}