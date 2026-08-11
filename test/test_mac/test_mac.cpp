#include <BareUtils.h>
#include <cstring>
#include <unity.h>

void setUp(void) {}
void tearDown(void) {}

void test_mac_to_string(void) {
  uint8_t mac[6] = {0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC};
  char macText[18];

  Utils::macToString(mac, macText, sizeof(macText));
  TEST_ASSERT_EQUAL_STRING("12:34:56:78:9A:BC", macText);
}

void test_mac_to_string_buffer_too_small(void) {
  uint8_t mac[6] = {0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC};
  char smallBuffer[6] = {0};

  Utils::macToString(mac, smallBuffer, sizeof(smallBuffer));

  TEST_ASSERT_EQUAL_STRING("12:34", smallBuffer);
}

void test_mac_to_string_buffer_oversized(void) {
  uint8_t mac[6] = {0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC};
  char largeBuffer[50];
  memset(largeBuffer, 'X', sizeof(largeBuffer));

  Utils::macToString(mac, largeBuffer, sizeof(largeBuffer));

  TEST_ASSERT_EQUAL_STRING_LEN("12:34:56:78:9A:BC", largeBuffer, 17);
  TEST_ASSERT_EQUAL_CHAR('\0', largeBuffer[17]);
  TEST_ASSERT_EQUAL_CHAR('X', largeBuffer[18]);
}

void test_mac_to_string_edge_cases(void) {
  uint8_t macZeros[6] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  char textZeros[18];
  Utils::macToString(macZeros, textZeros, sizeof(textZeros));
  TEST_ASSERT_EQUAL_STRING("00:00:00:00:00:00", textZeros);

  uint8_t macMax[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
  char textMax[18];
  Utils::macToString(macMax, textMax, sizeof(textMax));
  TEST_ASSERT_EQUAL_STRING("FF:FF:FF:FF:FF:FF", textMax);
}

void test_string_to_mac(void) {
  const char* macText = "00:1A:2B:3C:4D:5E";
  uint8_t mac[6] = {0};
  Utils::stringToMac(macText, mac);

  uint8_t expectedMac[6] = {0x00, 0x1A, 0x2B, 0x3C, 0x4D, 0x5E};
  TEST_ASSERT_EQUAL_UINT8_ARRAY(expectedMac, mac, 6);
}

void test_string_to_mac_lowercase(void) {
  const char* macText = "aa:1b:2c:3d:4e:5f";
  uint8_t mac[6] = {0};
  Utils::stringToMac(macText, mac);

  uint8_t expectedMac[6] = {0xAA, 0x1B, 0x2C, 0x3D, 0x4E, 0x5F};
  TEST_ASSERT_EQUAL_UINT8_ARRAY(expectedMac, mac, 6);
}

int main(int argc, char** argv) {
  UNITY_BEGIN();
  RUN_TEST(test_mac_to_string);
  RUN_TEST(test_mac_to_string_buffer_too_small);
  RUN_TEST(test_mac_to_string_buffer_oversized);
  RUN_TEST(test_mac_to_string_edge_cases);

  RUN_TEST(test_string_to_mac);
  RUN_TEST(test_string_to_mac_lowercase);
  return UNITY_END();
}
