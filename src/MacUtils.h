#pragma once

#include <stddef.h>
#include <stdint.h>

namespace Utils {
  /**
   * @brief Converts a binary MAC address (6 bytes) into a formatted hex string
   * @param mac Pointer to the 6-byte binary MAC array
   * @param macText Destination character buffer (minimum 18 bytes recommended)
   * @param size Size of the destination buffer
   */
  void macToString(const uint8_t* mac, char* macText, size_t size);

  /**
   * @brief Parses a formatted MAC address string into its 6-byte binary
   * representation.
   * @param input Formatted MAC string (e.g., "AA:BB:CC:11:22:33").
   * @param mac Destination 6-byte array where the result will be stored.
   */
  void stringToMac(const char* input, uint8_t mac[6]);
}
