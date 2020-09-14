#ifndef ULS_PROTOTYPES_H
#define ULS_PROTOTYPES_H

#include "structures.h"

#define LS_VALID_STR_ONE "&func_name: illegal option -- &invalflag \n"
#define LS_VALID_STR_TWO "usage: &func_name  [-&val_flags]] [file ...]"
#define LS_VALID_FLAGS "ACGRSTaclmrtu1"
#define LS_CLEAR_STR "*-aA*+lh@eT*--rtucS*--1Cml"
#define LS_FUNC_NAME "uls"


/* Base */
t_main *init_main(int argc, char **argv);
char **init_files(int argc, char **argv);
char *init_flags(int argc, char **argv);
void run(t_main *main);
void loop(char **files, t_main *main, bool print);

/* Validate */
void validate_flags(char *str, char *f_name,  char *flags, char *v_flags);
char *clear_flags(char *flags, char *valid_str);

/* Utils */
int get_arr_size(char **arr);
t_file **malloc_struct_array(int size);
bool find_in_str(const char *string, char sought);
int count_in_dir(char *dir_path, int hidden);
void swap_files(t_file **file1, t_file **file2)


/* Parsers */
t_file *get_lstat(const char *file);
int get_term_width(void);
int get_hidden(char *flags);
char **read_dir(char *dir, int hidden);
char get_file_type(int file_mode);
char *get_name(const char *file);
char get_color(struct stat buf);

/* Sorting */
void run_sort(t_file **files, char *flags, int size);

#endif //ULS_PROTOTYPES_H
