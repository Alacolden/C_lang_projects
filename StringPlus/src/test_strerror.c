#include <check.h>
#include <string.h>

#include "s21_string.h"

START_TEST(test_strerror) {
  int i = 0;
  for (i = -30; i < 140; i += 1) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
}
END_TEST
START_TEST(s21_strerror_test_1) {
  ck_assert_pstr_eq(s21_strerror(150), strerror(150));
}
END_TEST

int main(void) {
  Suite *s = suite_create("Core");
  TCase *tc = tcase_create("Core");
  SRunner *srun = srunner_create(s);
  int sf = 0;
  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_strerror);
  tcase_add_test(tc, s21_strerror_test_1);

  srunner_run_all(srun, CK_ENV);
  sf = srunner_ntests_failed(srun);
  srunner_free(srun);
  return sf == 0 ? 0 : 1;
}
