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

static char *pop_char(char *string, int index)
{
    int len;
    char *result = NULL;

    if (string)
    {
        len = mx_strlen(string);
        result = mx_strnew(len - 1);
        for (int i = 0; i < len; i++)
        {
            if (i < index)
                result[i] = string[i];
            else
                result[i] = string[i + 1];
        }
    }
    return result;
}

static char *check_file(const char *file, unsigned short int file_mode)
{
    char *result = mx_strdup(file);
    char *tmp;
    char type = get_file_type(file_mode);

    if (file)
    {
        for (int i = 0; result[i] ; i++)
            if (result[i] == '/' && result[i + 1] == '/' && type != 'd')
            {
                tmp = mx_strdup(result);
                mx_strdel(&result);
                result = pop_char(tmp, i + 1);
                mx_strdel(&tmp);
                i--;
            }
    }
    return result;
}

t_file *get_lstat(const char *file)
{
    struct stat buf_l;
    lstat(file, &buf_l);
    t_file *new_file_s = malloc(sizeof(t_file));
    char *user_name = get_user_name(buf_l.st_uid);
    char *group_name = get_group_name(buf_l.st_gid);

    new_file_s->name = check_file(file, buf_l.st_mode);
    new_file_s->print_name = get_name(file);
    new_file_s->acl_inf = acl_to_text(acl_get_file(file, ACL_TYPE_DEFAULT), NULL);  //ToDo: Mac change to ACL_TYPE_EXTENDED
    new_file_s->type = get_file_type(buf_l.st_mode);
    new_file_s->color = get_color(buf_l);
    new_file_s->mode = buf_l.st_mode;
    new_file_s->size = buf_l.st_size;
    new_file_s->nlink = buf_l.st_nlink;
    new_file_s->uid_name = user_name;
    new_file_s->gid_name = group_name;
    new_file_s->blksize = buf_l.st_blksize;
    new_file_s->blocks = buf_l.st_blocks;
    new_file_s->atime = buf_l.st_atime;
    new_file_s->mtime = buf_l.st_mtime;
    new_file_s->ctime = buf_l.st_ctime;
    new_file_s->ino = buf_l.st_ino;
//    new_file_s->file_major = major(buf_l.st_rdev);
//    new_file_s->file_minor = minor(buf_l.st_rdev);

    return new_file_s;
}