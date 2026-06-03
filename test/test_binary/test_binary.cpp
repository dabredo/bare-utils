#include <BareUtils.h>
#include <string.h>
#include <unity.h>

void setUp(void) { }
void tearDown(void) { }

void test_bytes_to_hex(void) {
  uint8_t data[4] = { 0xDE, 0xAD, 0xBE, 0xEF };
  char hex[9];

  Utils::bytesToHex(data, 4, hex);
  TEST_ASSERT_EQUAL_STRING("DEADBEEF", hex);
}

void test_bytes_to_hex_edge_cases(void) {
  uint8_t data[2] = { 0x00, 0xFF };
  char hex[5];

  Utils::bytesToHex(data, 2, hex);
  TEST_ASSERT_EQUAL_STRING("00FF", hex);
}

void test_bytes_to_hex_buffer_oversized(void) {
  uint8_t data[2] = { 0x1A, 0x2B };
  char largeBuffer[20];
  memset(largeBuffer, 'X', sizeof(largeBuffer));

  Utils::bytesToHex(data, 2, largeBuffer);

  TEST_ASSERT_EQUAL_STRING_LEN("1A2B", largeBuffer, 4);
  TEST_ASSERT_EQUAL_CHAR('\0', largeBuffer[4]);
  TEST_ASSERT_EQUAL_CHAR('X', largeBuffer[5]);
}

void test_hex_to_bytes(void) {
  const char* hex = "A1B2C3D4";
  uint8_t resultBytes[4] = { 0 };

  Utils::hexToBytes(hex, resultBytes);

  uint8_t expectedBytes[4] = { 0xA1, 0xB2, 0xC3, 0xD4 };
  TEST_ASSERT_EQUAL_UINT8_ARRAY(expectedBytes, resultBytes, 4);
}

void test_hex_to_bytes_lowercase(void) {
  const char* hex = "a1b2c3d4";
  uint8_t resultBytes[4] = { 0 };

  Utils::hexToBytes(hex, resultBytes);

  uint8_t expectedBytes[4] = { 0xA1, 0xB2, 0xC3, 0xD4 };
  TEST_ASSERT_EQUAL_UINT8_ARRAY(expectedBytes, resultBytes, 4);
}

void test_hex_to_bytes_invalid_chars(void) {
  const char* hex = "A1G2Z3D4";
  uint8_t resultBytes[4] = { 0 };

  Utils::hexToBytes(hex, resultBytes);

  uint8_t expectedBytes[4] = { 0xA1, 0x02, 0x03, 0xD4 };
  TEST_ASSERT_EQUAL_UINT8_ARRAY(expectedBytes, resultBytes, 4);
}

void test_hex_to_bytes_odd_length(void) {
  const char* hex = "A1B2C3D";
  uint8_t resultBytes[4] = { 0xFF, 0xFF, 0xFF, 0xFF };

  Utils::hexToBytes(hex, resultBytes);

  uint8_t expectedBytes[4] = { 0xA1, 0xB2, 0xC3, 0xFF };
  TEST_ASSERT_EQUAL_UINT8_ARRAY(expectedBytes, resultBytes, 4);
}

int main(int argc, char** argv) {
  UNITY_BEGIN();

  RUN_TEST(test_bytes_to_hex);
  RUN_TEST(test_bytes_to_hex_edge_cases);
  RUN_TEST(test_bytes_to_hex_buffer_oversized);

  RUN_TEST(test_hex_to_bytes);
  RUN_TEST(test_hex_to_bytes_lowercase);
  RUN_TEST(test_hex_to_bytes_invalid_chars);
  RUN_TEST(test_hex_to_bytes_odd_length);

  return UNITY_END();
}
