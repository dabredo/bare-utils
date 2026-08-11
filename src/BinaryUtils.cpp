#include "BinaryUtils.h"

namespace Utils {
void bytesToHex(const uint8_t* data, int length, char* output) {
  static const char hexChars[] = "0123456789ABCDEF";
  for (int i = 0; i < length; i++) {
    output[i * 2] = hexChars[(data[i] >> 4) & 0x0F];
    output[i * 2 + 1] = hexChars[data[i] & 0x0F];
  }
  output[length * 2] = '\0';
}

void hexToBytes(const char* hex, uint8_t* bytes) {
  auto nibble = [](char chr) -> uint8_t {
    if (chr >= '0' && chr <= '9') {
      return chr - '0';
    }
    if (chr >= 'A' && chr <= 'F') {
      return chr - 'A' + 10;
    }
    if (chr >= 'a' && chr <= 'f') {
      return chr - 'a' + 10;
    }
    return 0;
  };

  while (*hex != '\0' && *(hex + 1) != '\0') {
    *bytes++ = (nibble(*hex) << 4) | nibble(*(hex + 1));
    hex += 2;
  }
}
} // namespace Utils
