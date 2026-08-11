#pragma once

#include <cstdint>

namespace Utils {
/**
 * @brief Converts a raw binary buffer into an uppercase hexadecimal string.
 * @param data Pointer to the binary source data.
 * @param length Length of the binary data in bytes.
 * @param output Destination character buffer (MUST be at least length * 2 + 1 bytes long).
 */
void bytesToHex(const uint8_t* data, int length, char* output);

/**
 * @brief Converts a hexadecimal string back into raw binary bytes.
 * @param hex Null-terminated hex string (e.g., "4A2F0E").
 * @param bytes Destination buffer for output bytes
 */
void hexToBytes(const char* hex, uint8_t* bytes);
} // namespace Utils
