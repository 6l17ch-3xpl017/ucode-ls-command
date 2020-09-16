#include "uls.h"

/**
 * Function sort files by names
 * @param files files array of file structs
 * @param size
 */
void sort_base(t_file **files, int size)
{
    t_file *temp_file;

    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            if (mx_strcmp(files[i]->print_name, files[j]->print_name) > 0) {
                temp_file = files[i];
                files[i] = files[j];
                files[j] = temp_file;
            }
        }
    }
}

/**
 * Function sorts files by creation time
 * @param files files array of file structs
 * @param size
 */
void sort_c(t_file **files, int size) {
    t_file *temp_file;

    for (int i = 0; i < size; ++i){
        for (int j = i; j < size; ++j) {
            if ((files[i]->ctime < files[j]->ctime)) {
                temp_file = files[i];
                files[i] = files[j];
                files[j] = temp_file;
            }
        }
    }

}

/**
 * Function sort recursive files
 * @param files files array of file structs
 * @param size
 */
void sort_r(t_file **files, int size) {
    for (int i = 0; i < size / 2; i++)
        swap_files(&files[i], &files[size - i - 1]);
}

/**
 * Function sort files by file size
 * @param files
 * @param size
 */
void sort_S(t_file **files, int size)
{
    t_file *temp_file;

    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            if ((files[i]->size < files[j]->size)) {
                temp_file = files[i];
                files[i] = files[j];
                files[j] = temp_file;
            } else {
                if (mx_strcmp(files[i]->print_name, files[i]->print_name) > 0)
                {
                    temp_file = files[i];
                    files[i] = files[j];
                    files[j] = temp_file;
                }
            }
        }
    }
}

/**
 * Function sort files by modification time
 * @param files array of file structs
 * @param size
 */
void sort_t(t_file **files, int size) {
    t_file *temp_file;

    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            if ((files[i]->mtime < files[j]->mtime) && files[i]->mtime != files[j]->mtime) {
                temp_file = files[i];
                files[i] = files[j];
                files[j] = temp_file;
            } else {
                if (mx_strcmp(files[i]->print_name, files[j]->print_name) > 0) {
                    temp_file = files[i];
                    files[i] = files[j];
                    files[j] = temp_file;
                }
            }
        }
    }
}

/**
 * Function sort files by access time
 * @param files files array of file structs
 * @param size
 */
void sort_u(t_file **files, int size)
{
    t_file *temp_file;

    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            if ((files[i]->atime < files[j]->atime)) {
                temp_file = files[i];
                files[i] = files[j];
                files[j] = temp_file;
            } else {
                if (mx_strcmp(files[i]->print_name, files[j]->print_name) > 0)
                {
                    temp_file = files[i];
                    files[i] = files[j];
                    files[j] = temp_file;
                }
            }
        }
    }
}

void run_sort(t_file **files, char *flags, int size)
{
    sort_base(files, size);
    if (find_in_str(flags, 'c'))
        sort_c(files, size);
    if (find_in_str(flags, 'r'))
        sort_r(files, size);
    if (find_in_str(flags, 'S'))
        sort_S(files, size);
    if (find_in_str(flags, 't'))
        sort_t(files, size);
    if (find_in_str(flags, 'u'))
        sort_u(files, size);
}
