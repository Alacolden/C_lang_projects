#include <check.h>
#include <stdlib.h>

#include "s21_matrix.h"

START_TEST(test_create_matrix) {
  matrix_t matrix;
  int result = s21_create_matrix(3, 3, &matrix);
  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(matrix.rows, 3);
  ck_assert_int_eq(matrix.columns, 3);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_create_matrix_invalid) {
  matrix_t matrix;
  int result = s21_create_matrix(0, 3, &matrix);
  ck_assert_int_eq(result, INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_eq_matrix) {
  matrix_t A, B;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;

  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = 2.0;
  B.matrix[1][0] = 3.0;
  B.matrix[1][1] = 4.0;

  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix_not_equal) {
  matrix_t A, B;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;

  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = 2.0;
  B.matrix[1][0] = 3.0;
  B.matrix[1][1] = 5.0;

  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_sum_matrix) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;

  B.matrix[0][0] = 5.0;
  B.matrix[0][1] = 6.0;
  B.matrix[1][0] = 7.0;
  B.matrix[1][1] = 8.0;

  int code = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(code, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], 6.0, EPSILON);
  ck_assert_double_eq_tol(result.matrix[0][1], 8.0, EPSILON);
  ck_assert_double_eq_tol(result.matrix[1][0], 10.0, EPSILON);
  ck_assert_double_eq_tol(result.matrix[1][1], 12.0, EPSILON);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_sum_matrix_invalid_size) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(3, 3, &B);

  int code = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(code, CALC_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_sub_matrix) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  A.matrix[0][0] = 5.0;
  A.matrix[0][1] = 6.0;
  A.matrix[1][0] = 7.0;
  A.matrix[1][1] = 8.0;

  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = 2.0;
  B.matrix[1][0] = 3.0;
  B.matrix[1][1] = 4.0;

  int code = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(code, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], 4.0, EPSILON);
  ck_assert_double_eq_tol(result.matrix[0][1], 4.0, EPSILON);
  ck_assert_double_eq_tol(result.matrix[1][0], 4.0, EPSILON);
  ck_assert_double_eq_tol(result.matrix[1][1], 4.0, EPSILON);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_mult_number) {
  matrix_t A, result;
  s21_create_matrix(2, 2, &A);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;

  int code = s21_mult_number(&A, 2.0, &result);
  ck_assert_int_eq(code, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], 2.0, EPSILON);
  ck_assert_double_eq_tol(result.matrix[0][1], 4.0, EPSILON);
  ck_assert_double_eq_tol(result.matrix[1][0], 6.0, EPSILON);
  ck_assert_double_eq_tol(result.matrix[1][1], 8.0, EPSILON);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_mult_matrix) {
  matrix_t A, B, result;
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 2, &B);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;

  B.matrix[0][0] = 7.0;
  B.matrix[0][1] = 8.0;
  B.matrix[1][0] = 9.0;
  B.matrix[1][1] = 10.0;
  B.matrix[2][0] = 11.0;
  B.matrix[2][1] = 12.0;

  int code = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(code, OK);
  ck_assert_int_eq(result.rows, 2);
  ck_assert_int_eq(result.columns, 2);
  ck_assert_double_eq_tol(result.matrix[0][0], 58.0, EPSILON);
  ck_assert_double_eq_tol(result.matrix[0][1], 64.0, EPSILON);
  ck_assert_double_eq_tol(result.matrix[1][0], 139.0, EPSILON);
  ck_assert_double_eq_tol(result.matrix[1][1], 154.0, EPSILON);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_transpose) {
  matrix_t A, result;
  s21_create_matrix(2, 3, &A);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;

  int code = s21_transpose(&A, &result);
  ck_assert_int_eq(code, OK);
  ck_assert_int_eq(result.rows, 3);
  ck_assert_int_eq(result.columns, 2);
  ck_assert_double_eq_tol(result.matrix[0][0], 1.0, EPSILON);
  ck_assert_double_eq_tol(result.matrix[0][1], 4.0, EPSILON);
  ck_assert_double_eq_tol(result.matrix[1][0], 2.0, EPSILON);
  ck_assert_double_eq_tol(result.matrix[1][1], 5.0, EPSILON);
  ck_assert_double_eq_tol(result.matrix[2][0], 3.0, EPSILON);
  ck_assert_double_eq_tol(result.matrix[2][1], 6.0, EPSILON);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_determinant_1x1) {
  matrix_t A;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 5.0;

  double det;
  int code = s21_determinant(&A, &det);
  ck_assert_int_eq(code, OK);
  ck_assert_double_eq_tol(det, 5.0, EPSILON);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_2x2) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;

  double det;
  int code = s21_determinant(&A, &det);
  ck_assert_int_eq(code, OK);
  ck_assert_double_eq_tol(det, -2.0, EPSILON);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_3x3) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;
  A.matrix[2][0] = 7.0;
  A.matrix[2][1] = 8.0;
  A.matrix[2][2] = 9.0;

  double det;
  int code = s21_determinant(&A, &det);
  ck_assert_int_eq(code, OK);
  ck_assert_double_eq_tol(det, 0.0, EPSILON);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_calc_complements_2x2) {
  matrix_t A, result;
  s21_create_matrix(2, 2, &A);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;

  int code = s21_calc_complements(&A, &result);
  ck_assert_int_eq(code, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], 4.0, EPSILON);
  ck_assert_double_eq_tol(result.matrix[0][1], -3.0, EPSILON);
  ck_assert_double_eq_tol(result.matrix[1][0], -2.0, EPSILON);
  ck_assert_double_eq_tol(result.matrix[1][1], 1.0, EPSILON);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_inverse_matrix_2x2) {
  matrix_t A, result;
  s21_create_matrix(2, 2, &A);

  A.matrix[0][0] = 4.0;
  A.matrix[0][1] = 3.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 2.0;

  int code = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(code, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], -2.0, EPSILON);
  ck_assert_double_eq_tol(result.matrix[0][1], 3.0, EPSILON);
  ck_assert_double_eq_tol(result.matrix[1][0], 3.0, EPSILON);
  ck_assert_double_eq_tol(result.matrix[1][1], -4.0, EPSILON);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_inverse_matrix_singular) {
  matrix_t A, result;
  s21_create_matrix(2, 2, &A);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 2.0;
  A.matrix[1][1] = 4.0;

  int code = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(code, CALC_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

Suite *matrix_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Matrix");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_create_matrix);
  tcase_add_test(tc_core, test_create_matrix_invalid);
  tcase_add_test(tc_core, test_eq_matrix);
  tcase_add_test(tc_core, test_eq_matrix_not_equal);
  tcase_add_test(tc_core, test_sum_matrix);
  tcase_add_test(tc_core, test_sum_matrix_invalid_size);
  tcase_add_test(tc_core, test_sub_matrix);
  tcase_add_test(tc_core, test_mult_number);
  tcase_add_test(tc_core, test_mult_matrix);
  tcase_add_test(tc_core, test_transpose);
  tcase_add_test(tc_core, test_determinant_1x1);
  tcase_add_test(tc_core, test_determinant_2x2);
  tcase_add_test(tc_core, test_determinant_3x3);
  tcase_add_test(tc_core, test_calc_complements_2x2);
  tcase_add_test(tc_core, test_inverse_matrix_2x2);
  tcase_add_test(tc_core, test_inverse_matrix_singular);

  suite_add_tcase(s, tc_core);
  return s;
}

int main(void) {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = matrix_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}