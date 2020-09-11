#include "uls.h"

static int get_longest_word(char **array)
{
    int current_longest[2] = {0, mx_strlen(array[0])}; // ToDo: Make structure
    int temp;

    for (int i = 1; array[i]; i++)
    {
        if ((temp = mx_strlen(array[i])) > current_longest[1])
        {
            current_longest[0] = i;
            current_longest[1] = temp;
        }
    }

    if ((temp = current_longest[1] % 8))
        current_longest[1] += 8 - temp;

//    return (current_longest[1] * 100000) + current_longest[0]; // FixMe: Delete this line
    return current_longest[1];
}

int print_base(char *dir_path) {                          //ToDo: Check Errors
    struct dirent *pDirent;
    char **file_and_folders = malloc_array(
            count_in_dir(dir_path, DT_ALL) - 2); // ToDo: Make method to malloc file_and_folders array
    DIR *pDir = opendir(dir_path);

    //ToDo: print nothing if count_in_dir == 0;
    for (int i = 0; (pDirent = readdir(pDir)) != NULL;) {
        if (pDirent->d_name[0] != '.') {
            file_and_folders[i] = malloc(strlen(pDirent->d_name) + 1);
            mx_strcpy(file_and_folders[i++], pDirent->d_name);
            printf("%s\n", pDirent->d_name);

        }
    }

    int longest_size = get_longest_word(file_and_folders);
    int arr_size = 0; // ToDo: Check it

    while (file_and_folders[arr_size++]);  //ToDo: Check result
    arr_size--;

    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    w.ws_row = 12;
    w.ws_col = 12;
    //ToDo: Sort array ?
    for (int i = 0; file_and_folders[i] != NULL; i++)
        if (file_and_folders[i][0] != '.')
        {
            if (isatty(1))
            {
                if ((arr_size * longest_size) >= w.ws_col && (w.ws_col > 0 && w.ws_row > 0))
                {
                    int rows = (w.ws_col += w.ws_col % longest_size) / longest_size;
                    int cols = (arr_size & 1 ? arr_size + 1: arr_size)  / rows; // Round number

                    if (cols % rows != 0)
                        cols++;

                    int count = 0;
                    int count_c = 0;
                    int k = 0;
                    while (count_c <= cols)
                    {
                        i = k;
                        while (count != rows) {
                            mx_printstr(file_and_folders[i]);

                            for (int j = 0; j != longest_size - mx_strlen(file_and_folders[i]); j++)
                                if (count + 1 != rows)
                                    mx_printchar(' ');

                                 count++;
                            i += cols;
                        }
                        mx_printchar('\n');
                        count = 0;
                        count_c++;
                        k++;
                    }
                    return 0;
                }

                else
                {
                    printf("%s", file_and_folders[i]);
                    for (int j = 0; j != longest_size - mx_strlen(file_and_folders[i]); j++)
                        printf(" ");
                    printf("  ");
                }

            }
            else
                printf("%s\n", file_and_folders[i]);
        }

    /*
     * ToDo: Why uls == cmake-build-debug CMakeLists.txt inc main.c src test !=
     * ToDo: ls == CMakeLists.txt  cmake-build-debug  inc  main.c  src  test
     * ToDo: Test this
     */

    return 0;
}

