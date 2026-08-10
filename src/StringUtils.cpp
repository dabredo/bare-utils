#include "StringUtils.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

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

  const char *numberToText(uint32_t number) {
    static char circularBuffers[4][12];
    static uint8_t currentBuffer = 0;

    currentBuffer = (currentBuffer + 1) % 4;
    ultoa(number, circularBuffers[currentBuffer], 10);

    return circularBuffers[currentBuffer];
  }

  char* buildParts(char* destination, std::initializer_list<const char*> parts) {
    if (destination == nullptr) return nullptr;

    char* ptr = destination;

    for (const char* part : parts) {
      if (part != nullptr) {
        while (*part != '\0') {
          *ptr++ = *part++;
        }
      }
    }

    *ptr = '\0';
    return destination;
  }
}
