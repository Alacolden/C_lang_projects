#ifndef S21_OTHER_H
#define S21_OTHER_H

#include "../../s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);
int s21_truncate_with_remainder(s21_decimal value, s21_decimal *result,
                                int *remainder);

#endif