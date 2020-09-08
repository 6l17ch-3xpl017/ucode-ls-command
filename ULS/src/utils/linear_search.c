#include "uls.h"

bool linear_search(char *word, char **array)
{
    int result;

    for (int i = 0; (result = strcmp(word, array[i])) != 0; i++);

    return result == 0;
}