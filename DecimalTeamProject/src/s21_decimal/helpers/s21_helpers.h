#ifndef S21_BIT_UTILS_H
#define S21_BIT_UTILS_H

#include "../../s21_decimal.h"

int s21_get_scale(s21_decimal value);
void s21_set_scale(s21_decimal *value, unsigned int scale);
int s21_get_sign(s21_decimal value);
void s21_set_sign(s21_decimal *value, unsigned int sign);
void s21_set_big_bit(s21_big_decimal *v, unsigned int index, int bit);

int s21_check_big_to_decimal(s21_big_decimal value);
s21_big_decimal s21_decimal_to_big(s21_decimal value);
void s21_big_to_decimal(s21_big_decimal big_decimal, s21_decimal *decimal);

int s21_is_decimal_zero(s21_decimal value);
int s21_is_big_decimal_zero(s21_big_decimal value);
void s21_value_copy(s21_decimal value, s21_decimal *result);
int s21_is_decimal_one(s21_decimal value, unsigned int scale);

int s21_mult_big_by_ten_power(s21_big_decimal *value, unsigned int power);
int s21_add_big_decimal(s21_big_decimal value_1, s21_big_decimal value_2,
                        s21_big_decimal *result);
void s21_sub_big_decimal(s21_big_decimal value_1, s21_big_decimal value_2,
                         s21_big_decimal *result);
int s21_div_big_by_ten(s21_big_decimal *value);
int s21_add_one_to_big(s21_big_decimal *value);
int s21_big_rounding(s21_big_decimal *value, unsigned int *scale);
int s21_reduce_scale(s21_big_decimal *result_bd, unsigned int *result_scale,
                     unsigned int result_sign);

int normalize_scales(s21_decimal *a, s21_decimal *b);
int compare_mantissa(s21_decimal a, s21_decimal b);
int left_shift(s21_decimal *value, int shift);
int big_to_decimal(s21_big_decimal big, s21_decimal *result, int scale);

#endif