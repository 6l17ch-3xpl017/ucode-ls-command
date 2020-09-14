#include "uls.h"

char get_file_type(int file_mode)
{
    switch (file_mode & S_IFMT)
    {
        case S_IFBLK: return '-';
        case S_IFREG: if ((file_mode & S_IXUSR) == S_IXUSR) return '-';
        case S_IFCHR: return 'c';
        case S_IFIFO: return 'p';
        case S_IFSOCK: return 's';
        case S_IFDIR: return 'd';
        case S_IFLNK: return 'l';
    }
    return '-';
}