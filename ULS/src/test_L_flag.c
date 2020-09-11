#include "uls.h"

//ToDo: Ваня тут я пытаюсь поробовать как работает по хорошему
// нужно сделтаь стркутру файлов и мейна и тд смотри в папке inc

static void print_rights(struct stat buf)
{
    printf(((((buf.st_mode) & 0170000) == 0040000)) ? "d" : "-");
    printf( (buf.st_mode & S_IRUSR) ? "r" : "-");
    printf( (buf.st_mode & S_IWUSR) ? "w" : "-");
    printf( (buf.st_mode & S_IXUSR) ? "x" : "-");
    printf( (buf.st_mode & S_IRGRP) ? "r" : "-");
    printf( (buf.st_mode & S_IWGRP) ? "w" : "-");
    printf( (buf.st_mode & S_IXGRP) ? "x" : "-");
    printf( (buf.st_mode & S_IROTH) ? "r" : "-");
    printf( (buf.st_mode & S_IWOTH) ? "w" : "-");
    printf( (buf.st_mode & S_IXOTH) ? "x" : "-");
    mx_printchar('\t');
}

static t_time *get_time(__darwin_time_t time)
{
    char *string_time = ctime(&time);
    string_time[mx_strlen(string_time)] = '\0';
    char **time_parts = mx_strsplit(string_time, ' ');
    t_time *s_time = malloc(sizeof(t_time));

    s_time->day_of_week = mx_strdup(time_parts[0]);
    s_time->month = mx_strdup(time_parts[1]);
    s_time->day = mx_strdup(time_parts[2]);
    s_time->time = mx_strdup(time_parts[3]);
    s_time->time[5] = '\0';
    s_time->year = mx_strdup(time_parts[4]);

    mx_del_strarr(&time_parts);

    return s_time;
}

int print_l(char *dir_path)
{
    DIR *pDir = opendir(dir_path);
    struct dirent *pDirent;
    struct s_stat;

    struct stat buf;
    struct passwd *structpasswd;
    struct group *structgroup;
    t_time *s_time;

    lstat(dir_path, &buf);

    while ((pDirent = readdir(pDir)) != NULL)
    {
        lstat(pDirent->d_name, &buf); //ToDo Concatenate with file path
        print_rights(buf);
        printf("%d", buf.st_nlink);
        structpasswd = getpwuid(buf.st_uid);
        printf("\t%s", structpasswd->pw_name);
        structgroup = getgrgid(buf.st_gid);
        printf("\t%s", structgroup != NULL ? structgroup->gr_name : mx_itoa(buf.st_gid));
        printf("%d", buf.st_blksize); // ToDo: Add flag -h
        s_time = get_time(buf.st_mtimespec.tv_sec);
        printf("%s %s %s ",
               s_time->month, s_time->day,time(NULL) - buf.st_mtimespec.tv_sec >= 31536000 ? s_time->year : s_time->time);
        printf("%s\n", pDirent->d_name);
    }

    return 0;
}