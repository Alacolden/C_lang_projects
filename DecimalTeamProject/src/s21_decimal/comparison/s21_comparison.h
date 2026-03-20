#ifndef S21_COMPARISON_H
#define S21_COMPARISON_H

#include "../../s21_decimal.h"

int s21_is_less(s21_decimal a, s21_decimal b);
int s21_is_less_or_equal(s21_decimal a, s21_decimal b);
int s21_is_greater(s21_decimal a, s21_decimal b);
int s21_is_greater_or_equal(s21_decimal a, s21_decimal b);
int s21_is_equal(s21_decimal a, s21_decimal b);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);
int s21_compare_big_decimal(s21_big_decimal value_1, s21_big_decimal value_2);

#endif