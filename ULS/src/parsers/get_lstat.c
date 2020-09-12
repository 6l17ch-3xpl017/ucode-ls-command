#include "uls.h"

static char *get_group_name(int st_gid)
{
    struct group *s_group = getgrgid(st_gid);

    if (s_group)
        return mx_strdup(s_group->gr_name);

    else
        return mx_itoa(st_gid);
}

static char *get_user_name(int st_uid)
{
    struct passwd *pswd;
    char *id_string = mx_itoa(st_uid);

    pswd = getpwuid(st_uid);
    if (pswd)
    {
        mx_strdel(&id_string);
        return mx_strdup(pswd->pw_name);
    }
    return id_string;
}

t_file *get_lstat(const char *file)
{
    struct stat buf_l;
    lstat(file, &buf_l);
    t_file *new_file_s = malloc(sizeof(t_file));
    char *group_name = get_group_name(buf_l.st_gid);
    char *user_name = get_user_name(buf_l.st_uid);

    new_file_s->name =
}