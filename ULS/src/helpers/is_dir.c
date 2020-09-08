#include "uls.h"

bool is_dir(char *filename)
{
  struct stat buf;
  stat(filename, &buf);

  return ((((buf.st_mode)) & 0170000) == (0040000));
}