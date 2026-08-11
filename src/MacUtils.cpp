#include "MacUtils.h"

#include <cstdio>

namespace Utils {
void macToString(const uint8_t* mac, char* macText, size_t size) {
  snprintf(macText, size, "%02X:%02X:%02X:%02X:%02X:%02X", mac[0], mac[1], mac[2], mac[3], mac[4],
           mac[5]);
}

void stringToMac(const char* input, uint8_t mac[6]) {
  sscanf(input, "%hhx:%hhx:%hhx:%hhx:%hhx:%hhx", &mac[0], &mac[1], &mac[2], &mac[3], &mac[4],
         &mac[5]);
}
} // namespace Utils
