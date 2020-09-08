#include "uls.h"

int print_base(char *dir_path) {                          //ToDo: Check Errors
    struct dirent *pDirent;
    char **file_and_folders = malloc_array(
            count_in_dir(dir_path, DT_ALL)); // ToDo: Make method to malloc file_and_folders array
    DIR *pDir = opendir(dir_path);

    //ToDo: print nothing if count_in_dir == 0;
    for (int i = 0; (pDirent = readdir(pDir)) != NULL; i++) {
        file_and_folders[i] = malloc(strlen(pDirent->d_name) + 1);
        strcpy(file_and_folders[i], pDirent->d_name);
    }
    //ToDo: Sort array ?
    for (int i = 0; file_and_folders[i] != NULL; i++)
        if (file_and_folders[i][0] != '.')
            printf("%s ", file_and_folders[i]);

    /*
     * ToDo: Why uls == cmake-build-debug CMakeLists.txt inc main.c src test !=
     * ToDo: ls == CMakeLists.txt  cmake-build-debug  inc  main.c  src  test
     * ToDo: Test this
     */

    return 0;
}

