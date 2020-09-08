#ifndef ULS_ULS_H
#define ULS_ULS_H

#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
//*******************//*
#include <malloc.h>  //*
#include <string.h>  //*
#include <stdio.h>   //*
#include <unistd.h>  //*
#include <fcntl.h>   //*
#include <stdbool.h> //*
//*******************//*
#ifdef __APPLE__
#include <sys/uio.h>
#else
#include <sys/io.h>
#endif
#include <sys/stat.h>
//#include <sys/acl.h>

/* Structures */
typedef struct s_request
{
    char *start_path;
    char **files;
    char **dirs;
    char **flags;
}              t_request;

/* Defines */
enum
{
    DT_ALL = -1
    #define DT_ALL		DT_ALL
};

/* Prototypes */

    /* Helpers */
        int print_base(char *dir_path);
        bool is_dir(char *filename);
        bool is_file(char *filename);

    /* Base */
        int run(int argc, char **argv);

    /* Utils */
        int count_in_dir(char *dir_path, int d_type);
        char **malloc_array(size_t size);


#endif //ULS_ULS_H
