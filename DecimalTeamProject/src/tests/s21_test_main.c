#include <check.h>
#include <stdio.h>
#include <stdlib.h>

Suite *test_s21_arif(void);
Suite *test_s21_equals(void);
Suite *test_s21_func(void);
Suite *test_s21_conversion(void);

int main(void) {
  int number_failed = 0;
  Suite *s;
  SRunner *sr;

  printf("========================================\n");
  printf("Running arithmetic tests...\n");
  printf("========================================\n");

  s = test_s21_arif();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  printf("\n========================================\n");
  printf("Running comparison tests...\n");
  printf("========================================\n");

  s = test_s21_equals();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  printf("\n========================================\n");
  printf("Running conversion tests...\n");
  printf("========================================\n");

  s = test_s21_conversion();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  printf("\n========================================\n");
  printf("Running other function tests...\n");
  printf("========================================\n");

  s = test_s21_func();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  printf("\n========================================\n");
  printf("Total failed tests: %d\n", number_failed);
  printf("========================================\n");

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}