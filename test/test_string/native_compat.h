#pragma once

#if !defined(ARDUINO) && !defined(ESP_PLATFORM)
#include <stdint.h>
#include <stdio.h>

static inline char* ultoa(uint32_t val, char* str, int base) {
  snprintf(str, 12, "%u", val);
  return str;
}
#endif
