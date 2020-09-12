#include "uls.h"

static bool get_result(char *d_name, int hidden, int *i)
{
    if ((hidden == 0 && d_name[0] == '.') ||
        (hidden == 2 && (!mx_strcmp(d_name, ".") ||
        !mx_strcmp(d_name, ".."))))
        *i -= 1;
    else
        return true;
    return false;
}

char **read_dir(char *dir, int hidden)
{
    DIR *pDir = opendir(dir);
    struct dirent *pDirent = NULL;
    int files = count_in_dir(dir, hidden);
    char **result = NULL;

    if (!pDir || files < 0) return NULL;

    result = malloc(sizeof(char *) * (files + 1));
    pDirent = readdir(pDir);

    for (int i = 0; i < files; i++)
    {
        if (get_result(pDirent->d_name, hidden, &i))
        {
            char *mem = mx_strjoin(dir, "/");
            result[i] = mx_strjoin(mem, pDirent->d_name);
            mx_strdel(&mem);
        }
        pDirent = readdir(pDir);
    }
    result[files] = NULL;
    closedir(pDir);
    return result;
}
