#include "StringUtils.h"

#include <cctype>
#include <cstdlib>
#include <cstring>

namespace Utils {
void trim(char* string) {
  char* start = string;
  while (*start != '\0' && std::isspace(static_cast<unsigned char>(*start)) != 0) {
    start++;
  }

  if (start != string) {
    memmove(string, start, strlen(start) + 1);
  }

  char* end = string + strlen(string) - 1;
  while (end >= string && std::isspace(static_cast<unsigned char>(*end)) != 0) {
    *end = '\0';
    end--;
  }
}

const char* numberToText(uint32_t number) {
  static char circularBuffers[4][12];
  static uint8_t currentBuffer = 0;

  currentBuffer = (currentBuffer + 1) % 4;
  utoa(number, circularBuffers[currentBuffer], 10);

  return circularBuffers[currentBuffer];
}

char* buildParts(char* destination, std::initializer_list<const char*> parts) {
  if (destination == nullptr) {
    return nullptr;
  }

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
} // namespace Utils
