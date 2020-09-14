#include "uls.h"

/**
 * Function return size of null-terminated array
 * @param arr
 * @return size of array
 */
int get_arr_size(char **arr)
{
    int count = 0;
        for (int i = 1; arr[i]; i++)
            count++;
    return count;
}