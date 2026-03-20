#ifndef S21_ARITHM_H
#define S21_ARITHM_H

#include "../../s21_decimal.h"

#define LIMIT_BIG (BITS_BIG_DECIMAL - 1)
#define BIG_BITS_TOTAL (LIMIT_BIG * INT_BITS_COUNT)

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal reduced, s21_decimal subtract, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_carry_for_mul(s21_big_decimal *result, int index,
                      unsigned long long carry);
int s21_mul_big_decimal(s21_big_decimal value_1, s21_big_decimal value_2,
                        s21_big_decimal *result);
int s21_div_big_decimal(s21_big_decimal dividend, s21_big_decimal divisor,
                        s21_big_decimal *quotient, s21_big_decimal *remainder);

int s21_big_bit_length(const s21_big_decimal *v);
void s21_shl_big(s21_big_decimal *v, unsigned int n);
void s21_shr_big(s21_big_decimal *v, unsigned int n);
s21_big_decimal s21_div_big(s21_big_decimal dividend, s21_big_decimal divisor,
                            s21_big_decimal *quotient);
int s21_is_minimal_decimal(s21_decimal v);

#endif