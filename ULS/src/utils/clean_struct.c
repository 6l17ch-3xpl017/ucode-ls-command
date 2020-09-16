#include "uls.h"

static void clean(t_file **str) {
    free(*str);
    *str = NULL;
}

void clean_struct(t_file ***arr) {
    int i = 0;

    while ((*arr)[i]) {
        free((*arr)[i]->gid_name);
        free((*arr)[i]->uid_name);
        free((*arr)[i]->name);
        clean(&(*arr)[i]);
        i++;
    }
    free(*arr);
    *arr = NULL;
}