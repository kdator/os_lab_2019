#include <CUnit/Basic.h>
#include <stdio.h>
#include <string.h>

#include "/home/kdator/os_lab_2019/lab2/src/revert_string/revert_string.h"

void testRevertString(void) {
  char simple_string[] = "Hello";
  char str_with_spaces[] = "String with spaces";
  char str_with_odd_chars_num[] = "abc";
  char str_with_even_chars_num[] = "abcd";

  RevertString(simple_string);
  CU_ASSERT_STRING_EQUAL_FATAL(simple_string, "olleH");

  RevertString(str_with_spaces);
  CU_ASSERT_STRING_EQUAL_FATAL(str_with_spaces, "secaps htiw gnirtS");

  RevertString(str_with_odd_chars_num);
  CU_ASSERT_STRING_EQUAL_FATAL(str_with_odd_chars_num, "cba");

  RevertString(str_with_even_chars_num);
  CU_ASSERT_STRING_EQUAL_FATAL(str_with_even_chars_num, "dcba");
}

int main() {
  CU_pSuite pSuite = NULL;
  CU_pSuite first_suite = NULL;
  CU_pSuite second_suite = NULL;
  CU_pSuite third_suite = NULL;
  CU_pSuite fourth_suite = NULL;


  /* initialize the CUnit test registry */
  if (CUE_SUCCESS != CU_initialize_registry()) return CU_get_error();

  /* add a suite to the registry */
  pSuite = CU_add_suite("Suite", NULL, NULL);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  first_suite = CU_add_suite("First Suite", NULL, NULL);
    if (NULL == first_suite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  second_suite = CU_add_suite("Second Suite", NULL, NULL);
    if (NULL == second_suite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  third_suite = CU_add_suite("Third Suite", NULL, NULL);
    if (NULL == third_suite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  fourth_suite = CU_add_suite("Fourth Suite", NULL, NULL);
    if (NULL == fourth_suite) {
    CU_cleanup_registry();
    return CU_get_error();
  }


  /* add the tests to the suite */
  /* NOTE - ORDER IS IMPORTANT - MUST TEST fread() AFTER fprintf() */
  if ((NULL == CU_add_test(pSuite, "test of RevertString function",
                           testRevertString))) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if ((NULL == CU_add_test(first_suite, "test_1",
                           testRevertString))) {
    CU_cleanup_registry();
    return CU_get_error();
  }   

  if ((NULL == CU_add_test(second_suite, "check_2",
                           testRevertString))) {
    CU_cleanup_registry();
    return CU_get_error();
  }   

  if ((NULL == CU_add_test(third_suite, "see_3",
                           testRevertString))) {
    CU_cleanup_registry();
    return CU_get_error();
  }   

   if ((NULL == CU_add_test(fourth_suite, "test_4",
                           testRevertString))) {
    CU_cleanup_registry();
    return CU_get_error();
  }    

  /* Run all tests using the CUnit Basic interface */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();
  return CU_get_error();
}
