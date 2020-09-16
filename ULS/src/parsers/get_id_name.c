#include "uls.h"

/**
 * Function returns user name or group name or "-1" in case of erros
 * @param st_id id from stat
 * @param mode LS_GID for group id or LS_UID for user
 * @return
 */
char *get_id_name(int st_id, int mode)
{
    if (mode == LS_GID)
    {
        struct group *grp = getgrgid(st_id);
        char *grp_str = mx_itoa(st_id);

        if (grp)
        {
            mx_strdel(&grp_str);
            return mx_strdup(grp->gr_name);
        }

        return grp_str;
    }
    else if (mode == LS_UID)
    {
        struct passwd *pwd = getpwuid(st_id);
        char *pwd_str = mx_itoa(st_id);

        if (pwd)
        {
            mx_strdel(&pwd_str);
            return mx_strdup(pwd->pw_name);
        }
        return pwd_str;
    }
    return "-1";
}