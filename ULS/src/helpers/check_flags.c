#include "uls.h"

bool is_valid_flag(char *flag) {
  char *valid_flags[] = {"-l", "-a", "-R", NULL};
  if (linear_search(flag, valid_flags))
    return true;

  return false;
}


bool is_valid_option(char *option) {
  char *valid_options[] = {"--color", "--hello", "--bye", NULL};
  if (linear_search(option, valid_options))
    return true;

  return false;
}


void check_flags(t_request *request)
{
    int i = 0;
    while(request->flags[i][0]) {
      if (request->flags[i][1] != '-') {
        if (!is_valid_flag(request->flags[i])) {
          // ToDo: Change printf
          printf("uls: illegal option -- '%s'\n", request->flags[i]);
          printf("usage: uls [-l] [file ...]");
          exit(1);
        }
      } else {
        if (!is_valid_option(request->flags[i])) {
          // ToDo: Change printf
          printf("uls: unrecognized option -- '%s'\n", request->flags[i]);
          printf("usage: uls [-l] [file ...]");
        }
      }
      i++;
    }
}