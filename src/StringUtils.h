#pragma once

namespace Utils {
  /**
   * @brief Removes leading and trailing whitespace characters from a string.
   * @param string Pointer to the null-terminated string to trim.
   */
  void trim(char* string);

  /**
   * @brief Converts an unsigned 32-bit integer to a text string using a static circular buffer.
   * Allows up to 4 concurrent calls in the same scope without overwriting previous results.
   *
   * @param number The 32-bit unsigned integer to convert.
   * @return const char* Pointer to the null-terminated string representation of the number.
   */
  const char* numberToText(uint32_t number);
}
