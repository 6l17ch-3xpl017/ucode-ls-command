#ifndef ULS_ULS_H
#define ULS_ULS_H

#include "includes.h"
#include "structures.h"
#include "prototypes.h"
//#include <sys/types.h>
//#include <dirent.h>
//#include <errno.h>
////*******************//*
//#include <malloc.h>  //*
//#include <string.h>  //*
//#include <stdio.h>   //*
//#include <unistd.h>  //*
//#include <fcntl.h>   //*
//#include <stdbool.h> //*
//#include <stdlib.h>  //*
////*******************//*
#ifdef __APPLE__
#include <sys/uio.h>
#else

#include <sys/io.h>
#include <sys/types.h>
#include <sys/xattr.h>

#endif

#include <sys/stat.h>
#include <sys/acl.h>

/* Structures */
typedef struct s_request {
    char *start_path;
    char files[256][4096];
    char dirs[256][4096];
    char flags[256][4096];
} t_request;

/* Defines */
enum {
    DT_ALL = -1
#define DT_ALL        DT_ALL
};

//const char *valid_flags[] = {"l", "a", "R"};
//const char *valid_options[] = {"color", "hello", "bye"};
/* Prototypes */

/* Helpers */
int print_base(char *dir_path);

bool is_dir(char *filename);

bool is_file(char *filename);

bool linear_search(char *word, char **array);

void check_args(int argc, char **argv);

void check_flags(t_request *request);

/* Base */
int run(int argc, char **argv);

/* Utils */
int count_in_dir(char *dir_path, int d_type);
char *cutter(char * string, char separator, int a);
char **malloc_array(size_t size);


#endif //ULS_ULS_H
