#include "uls.h"

int get_num_len(unsigned long long int number) {
    int len = 0;

    for (unsigned long long int i = number; i != 0; i /= 10)
        len++;
    return len;
}
