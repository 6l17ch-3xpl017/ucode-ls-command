//
// Created by Иван on 08-Sep-20.
//
#include "uls.h"

char *cutter(char * string, char separator, int a) {
  if(!string)
    return NULL;
  if (a == 0)
    return string;
  char *stringEnd = string + strlen(string);
  while (a != 0)
  {
    if (*stringEnd != separator)
      stringEnd--;
    else{
      a--;
      stringEnd--;
    }
  }
  stringEnd++;
  *stringEnd = '\0';

  return string;
}