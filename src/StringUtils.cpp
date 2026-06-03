#include "StringUtils.h"
#include <ctype.h>
#include <string.h>

namespace Utils {
  void trim(char* string) {
    char* start = string;
    while (*start && isspace((unsigned char)*start)) {
      start++;
    }

    if (start != string) {
      memmove(string, start, strlen(start) + 1);
    }

    char* end = string + strlen(string) - 1;
    while (end >= string && isspace((unsigned char)*end)) {
      *end = '\0';
      end--;
    }
  }
}
