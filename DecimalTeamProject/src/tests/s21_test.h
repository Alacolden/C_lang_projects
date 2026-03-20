#ifndef S21_TEST_H
#define S21_TEST_H

#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_decimal/arithmetic/s21_arithm.h"
#include "../s21_decimal/comparison/s21_comparison.h"
#include "../s21_decimal/conversion/s21_conversion.h"
#include "../s21_decimal/other/s21_other.h"

Suite *test_s21_arif(void);
Suite *test_s21_equals(void);
Suite *test_s21_func(void);
Suite *test_s21_conversion(void);

#define SIGN_MINUS (unsigned)0b10000000000000000000000000000000
#define SIGN_BIT_MINUS UINT32_MAX - INT_MAX
#define DECIMAL_OUTPUT FALSE

#endif
