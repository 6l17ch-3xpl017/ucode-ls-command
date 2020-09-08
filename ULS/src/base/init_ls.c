#include "uls.h"

static t_request *parse_line(int argc, char **argv) {
    t_request *request = malloc(sizeof(t_request));
    request->files = malloc(argc); // ToDo: Use more advance method
    request->dirs = malloc(argc); // ToDo: Use more advance method
    request->flags = malloc(argc); // ToDo: Use more advance method
    request->start_path = strdup(argv[0]); // ToDo: Rename it
    int flags_count = 0;
    int dir_path_count = 0;

    for (int i = 1; i != argc; i++) {
        if (argv[i][0] == '-') {
            request->flags[flags_count] = malloc(strlen(argv[i]));
            strcpy(request->flags[flags_count++], argv[i]);
            continue;
        } else {
            if (is_dir(argv[i])) {
                request->dirs[dir_path_count] = malloc(strlen(argv[i]));
                strcpy(request->dirs[dir_path_count], argv[i]);
                continue;
            } else if (is_file(argv[i])) {
                request->files[dir_path_count] = malloc(strlen(argv[i]));
                strcpy(request->files[dir_path_count], argv[i]);
            }
        }
    }

    return request;
}

int print_files(t_request *request) {

    struct stat stat_buf;

    for (int i = 0; request->files[i]; i++)
    {
        stat(request->files[i], &stat_buf);
    }

    return 0;
}

int run(int argc, char **argv) {
    t_request *request = parse_line(argc, argv);
//    print(request);
    return 0;
}
