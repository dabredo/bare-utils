#include <BareUtils.h>
#include <cstdlib>
#include <unity.h>

void setUp(void) {}
void tearDown(void) {}

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

void test_number_to_text_basic_values(void) {
  TEST_ASSERT_EQUAL_STRING("0", Utils::numberToText(0));
  TEST_ASSERT_EQUAL_STRING("42", Utils::numberToText(42));
  TEST_ASSERT_EQUAL_STRING("123456", Utils::numberToText(123456));
  TEST_ASSERT_EQUAL_STRING("4294967295", Utils::numberToText(4294967295U)); // UINT32_MAX
}

void test_number_to_text_concurrent_buffers(void) {
  const char* ptr1 = Utils::numberToText(100);
  const char* ptr2 = Utils::numberToText(200);
  const char* ptr3 = Utils::numberToText(300);
  const char* ptr4 = Utils::numberToText(400);

  TEST_ASSERT_NOT_EQUAL(ptr1, ptr2);
  TEST_ASSERT_NOT_EQUAL(ptr2, ptr3);
  TEST_ASSERT_NOT_EQUAL(ptr3, ptr4);

  TEST_ASSERT_EQUAL_STRING("100", ptr1);
  TEST_ASSERT_EQUAL_STRING("200", ptr2);
  TEST_ASSERT_EQUAL_STRING("300", ptr3);
  TEST_ASSERT_EQUAL_STRING("400", ptr4);
}

void test_number_to_text_circular_buffer_overwrite(void) {
  const char* ptr1 = Utils::numberToText(111);
  Utils::numberToText(222);
  Utils::numberToText(333);
  Utils::numberToText(444);

  const char* ptr5 = Utils::numberToText(555);

  TEST_ASSERT_EQUAL_PTR(ptr1, ptr5);
  TEST_ASSERT_EQUAL_STRING("555", ptr1);
}

void test_build_parts_basic_concatenation(void) {
  char buffer[64];
  char* result = Utils::buildParts(buffer, {"Hello", " ", "world", "!"});

  TEST_ASSERT_EQUAL_STRING("Hello world!", buffer);
  TEST_ASSERT_EQUAL_PTR(buffer, result);
}

void test_build_parts_with_null_pointers(void) {
  char buffer[64];
  Utils::buildParts(buffer, {"abc", nullptr, "dfg", nullptr, "hij"});

  TEST_ASSERT_EQUAL_STRING("abcdfghij", buffer);
}

void test_build_parts_empty_list(void) {
  char buffer[64] = "previous content";
  Utils::buildParts(buffer, {});

  TEST_ASSERT_EQUAL_STRING("", buffer);
}

void test_build_parts_null_destination(void) {
  char* result = Utils::buildParts(nullptr, {"test", "123"});

  TEST_ASSERT_NULL(result);
}

void test_build_parts_combined_with_number_to_text(void) {
  char buffer[64];
  uint32_t deviceId = 12345678;

  Utils::buildParts(buffer, {"abc/", Utils::numberToText(deviceId), "/dfg"});

  TEST_ASSERT_EQUAL_STRING("abc/12345678/dfg", buffer);
}

int main(int argc, char** argv) {
  UNITY_BEGIN();

  RUN_TEST(test_string_trim_with_leading_and_trailing_spaces);
  RUN_TEST(test_string_trim_no_leading_or_trailing_spaces);
  RUN_TEST(test_string_trim_with_whitespace_only);
  RUN_TEST(test_string_trim_with_empty);

  RUN_TEST(test_number_to_text_basic_values);
  RUN_TEST(test_number_to_text_concurrent_buffers);
  RUN_TEST(test_number_to_text_circular_buffer_overwrite);

  RUN_TEST(test_build_parts_basic_concatenation);
  RUN_TEST(test_build_parts_with_null_pointers);
  RUN_TEST(test_build_parts_empty_list);
  RUN_TEST(test_build_parts_null_destination);
  RUN_TEST(test_build_parts_combined_with_number_to_text);

  return UNITY_END();
}
