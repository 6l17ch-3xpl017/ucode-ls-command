#include "uls.h"

/**
 * Count specific files in directories
 * @param dir_path path to directory
 * @param hidden option to check .. and . files
 * @return number of files in directory
 */
int count_in_dir(char *dir_path, int hidden) {
    DIR *pDir = opendir(dir_path);
    struct dirent *entry;
    int file_count = 0;

    if (!dir_path)
        return -1;

    while ((entry = readdir(pDir)) != NULL) {

        if ((hidden == 0 && entry->d_name[0] == '.')
        || (hidden == 2 && (!mx_strcmp(entry->d_name, ".")
        || !mx_strcmp(entry->d_name, ".."))))
            file_count--;

        file_count++;
    }

    closedir(pDir);
    return file_count;
}