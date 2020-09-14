#ifndef ULS_STRUCTURES_H
#define ULS_STRUCTURES_H

#include "includes.h"

typedef enum e_error {
    ERR_EACCES,
    ERR_DIR,
}            t_error;

typedef struct s_file {
    char *name;
    char *print_name;
    char *acl_inf;
    char type;
    char color;
    unsigned short int mode;
    long long int size;
    unsigned int nlink;
    char *uid_name;
    char *gid_name;
    int blksize;
    long long int blocks;
    long int atime;
    long int mtime;
    long int ctime;
    ino_t ino;
}              t_file;

typedef struct s_l_data {
    bool st;
    int max_uid;
    int max_gid;
    bool character_files;
    int max_size;
    time_t cur_time;
    bool check_dir;
    int max_link;
}              t_ls_l_data;

typedef struct s_main {
    char **files;
    t_file **files_struct;
    char *flags;
    bool color;
    int files_count;
    int terminal_width;
    bool is_term;
}              t_main;

#endif //ULS_STRUCTURES_H
