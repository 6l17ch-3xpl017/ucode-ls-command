//#include "uls.h"
//
//static t_request *parse_line(int argc, char **argv) {
//    t_request *request = malloc(sizeof(t_request));
//    for (int i = 0; i < 256; i++) {
//        request->dirs[i][0] = '\0';
//    }
//    for (int i = 0; i < 256; i++) {
//        request->files[i][0] = '\0';
//    }
//    for (int i = 0; i < 256; i++) {
//        request->flags[i][0] = '\0';
//    }
////    request->files = malloc(argc); // ToDo: Use more advance method  ToDo: /* Use realloc */
////    request->dirs = malloc(argc); // ToDo: Use more advance method         /* file is static char array[4096][256] */
////    request->flags = malloc(argc); // ToDo: Use more advance method        /* dirs and flag same */
//    request->start_path = strdup(argv[0]); // ToDo: Rename it
//    int flags_count = 0;
//    int dir_path_count = 0;
//    int files_count = 0;
//
//
//    // ToDo: add check len
//    for (int i = 1; i != argc; i++) {
//        if (argv[i][0] == '-')
//            strcpy(request->flags[flags_count++], argv[i]);
//        else
//        {
//            if (is_dir(argv[i]))
//                strcpy(request->dirs[dir_path_count++], argv[i]);
//
//            else if (is_file(argv[i]))
//                strcpy(request->files[files_count++], argv[i]);
//        }
//    }
//
//    return request;
//}
//
//// ToDo: Change return value to void
//static int print_files_base(t_request *request) {
//
//    for (int i = 0; request->files[i][0]; i++)
//        printf("%s  ", request->files[i]);
//
//    printf("\n\n");
//    return 0;
//}
//
//// ToDo: Change return value to void
//static int print_dir_base(t_request *request) {
//
//    for (int i = 0; request->dirs[i][0] ; i++) {
//        printf("%s:\n", request->dirs[i]);
//        print_base(request->dirs[i]);
//        printf("\n");
//    }
//
//    return 0;
//}
//
//int run(int argc, char **argv)
//{
//    check_args(argc, argv);
//    t_request *request = parse_line(argc, argv);
////    check_flags(request);
//    print_files_base(request);
//    print_dir_base(request);
//
//    return 0;
//}
