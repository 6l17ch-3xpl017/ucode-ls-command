#include "uls.h"

/**
 * Function initialize files to char array
 * @param argv arguments from main
 * @param argc quantity of arguments
 * @return null-terminated char array filed with files
 * If the function does not find files, it will return an array of size [1] and filled with NULL
 */
char **init_files(int argc, char **argv)
{
    char **files = malloc_char_array(argc);
    int files_count = 0;
    int i;

    /* Skip initial flags */
    for (i = 0; i < argc; i++)
        if (argv[i][0] != '-')
            break;

    /* Add files to files array */ //ToDo: Check files after '--' logic
    for (int j = i; j < argc && argv[j][0] != '-'; j++)
        files[files_count++] = mx_strdup(argv[j]);

    return files;
}
