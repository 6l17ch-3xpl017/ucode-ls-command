#ifndef ULS_STRUCTURES_H
#define ULS_STRUCTURES_H

#include "includes.h"

typedef enum e_error {
    ERR_EACCES,
    ERR_DIR,
}            t_error;

typedef struct s_file {
    char *name;              // full file name, example ./src/main.c
    char *print_name;        // short file name, example main.c
    char *acl_inf;           // needed for flag l (additional information)
    char type;               // file type
    char color;              // file color
    unsigned short int mode; // from it we get permissions and file type
    long long int size;      // size in bytes
    unsigned int nlink;      // number of file links needed for flag l
    char *uid_name;          // user name
    char *gid_name;          // group name
    int blksize;             // number of occupied blocks (in bytes)
    long long int blocks;    // number of occupied blocks (in blocks)
    long int atime;          // last access time
    long int mtime;          // last change time
    long int ctime;          // last change of access rights
    ino_t ino;               // file serial number
    int file_minor;
    int file_major;
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
    int str_size;
    int file_n;
    int terminal_width;
    bool out_in_terminal;
}              t_main;

#endif //ULS_STRUCTURES_H
