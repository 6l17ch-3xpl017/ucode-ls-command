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
t_ls_l_data *init_ls_data(t_file **files, t_main *main);
void run(t_main *main);
void loop(char **files, t_main *main, bool print);

/* Validate */
void validate_flags(char *str, char *f_name,  char *flags, char *v_flags);
char *clear_flags(char *flags, char *valid_str);
bool check_character_files(t_file **files);
char *valid_name(char *name);

/* Utils */
int get_arr_size(char **arr);
t_file **malloc_struct_array(int size);
bool find_in_str(const char *string, char sought);
int count_in_dir(char *dir_path, int hidden);
void swap_files(t_file **file1, t_file **file2);
int find_max_length_gid(t_file **files);
int find_max_length_uid(t_file **files);
int get_max_file_size(t_file **files);
int get_num_len(unsigned long long int number);
int get_max_size_nlink(t_file **files);
void print_color(t_file *ls, bool status);
void print_format_str(char *str, char local, char sym, int size);
void print_format_l(t_file *file, t_main *main, int size);
void maj_min_print(t_file *files);
char *get_time_str(t_file *file, t_ls_l_data *print_struct);

/* Parsers */
t_file *get_lstat(const char *file);
int get_term_width(void);
int get_hidden(char *flags);
char **read_dir(char *dir, int hidden);
char get_file_type(int file_mode);
char *get_name(const char *file);
char get_color(struct stat buf);
char *get_rights_str(int file_mode);
int get_xattr(char *file);

/* Sorting */
void run_sort(t_file **files, char *flags, int size);

/* Printers */
void print_rights(t_file *files);
void print_link_name(const char *file);

#endif //ULS_PROTOTYPES_H
