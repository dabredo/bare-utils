#include <BareUtils.h>
#include <unity.h>

void setUp(void) { }
void tearDown(void) { }

void test_string_trim_with_leading_and_trailing_spaces(void) {
  char text[] = "  hello world  ";
  Utils::trim(text);
  TEST_ASSERT_EQUAL_STRING("hello world", text);
}

void test_string_trim_no_leading_or_trailing_spaces(void) {
  char text[] = "no spaces";
  Utils::trim(text);
  TEST_ASSERT_EQUAL_STRING("no spaces", text);
}

void test_string_trim_with_whitespace_only(void) {
  char text[] = "   ";
  Utils::trim(text);
  TEST_ASSERT_EQUAL_STRING("", text);
}
void test_string_trim_with_empty(void) {
  char text[] = "";
  Utils::trim(text);
  TEST_ASSERT_EQUAL_STRING("", text);
}

int main(int argc, char** argv) {
  UNITY_BEGIN();

  RUN_TEST(test_string_trim_with_leading_and_trailing_spaces);
  RUN_TEST(test_string_trim_no_leading_or_trailing_spaces);
  RUN_TEST(test_string_trim_with_whitespace_only);
  RUN_TEST(test_string_trim_with_empty);

  return UNITY_END();
}
