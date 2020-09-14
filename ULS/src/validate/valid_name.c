#include "uls.h"

char *valid_name(char *name) {
    char *rep = NULL;
    char *new_rep = NULL;

    rep = mx_replace_substr(name, "\r", "?");
    new_rep = mx_replace_substr(rep, "\n", "?");
    mx_strdel(&rep);
    return new_rep;
}
