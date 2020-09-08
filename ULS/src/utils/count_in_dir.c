#include "uls.h"

/**
 * Count specific files in directories
 * @param dir_path path to directory
 * @param d_type file type for struct dirent. use DT_ALL to count all files
 * @return number of files in directory
 */
int count_in_dir(char *dir_path, int d_type) {
  int file_count = 0;
  DIR *pDir = opendir(dir_path);
  struct dirent *entry;

  while ((entry = readdir(pDir)) != NULL) {
    if (d_type == -1) {
      file_count++;
      continue;
    }
    if (entry->d_type == d_type)
      file_count++;
  }

  closedir(pDir);
  return file_count;
}