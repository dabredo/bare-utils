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
    auto nibble = [](char c) -> uint8_t {
      if (c >= '0' && c <= '9')
        return c - '0';
      if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;
      if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;
      return 0;
    };

    while (*hex && *(hex + 1)) {
      *bytes++ = (nibble(*hex) << 4) | nibble(*(hex + 1));
      hex += 2;
    }
  }
}
