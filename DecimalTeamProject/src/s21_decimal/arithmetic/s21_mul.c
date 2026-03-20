#include "../helpers/s21_helpers.h"
#include "s21_arithm.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = OK;
  for (int i = 0; i < 4; i++) result->bits[i] = 0;

  unsigned int sign_v1 = s21_get_sign(value_1), sign_v2 = s21_get_sign(value_2);
  unsigned int result_sign = (sign_v1 ^ sign_v2);
  unsigned int scale_v1 = s21_get_scale(value_1),
               scale_v2 = s21_get_scale(value_2);
  int is_decimal_zero =
      s21_is_decimal_zero(value_1) || s21_is_decimal_zero(value_2);
  int is_v1_one = s21_is_decimal_one(value_1, scale_v1),
      is_v2_one = s21_is_decimal_one(value_2, scale_v2);

  if ((is_v1_one || is_v2_one) && !is_decimal_zero) {
    if (is_v1_one) {
      s21_value_copy(value_2, result);
    } else {
      s21_value_copy(value_1, result);
    }
  } else if (!is_decimal_zero) {
    unsigned int result_scale = scale_v1 + scale_v2;
    s21_big_decimal bd_v1 = s21_decimal_to_big(value_1),
                    bd_v2 = s21_decimal_to_big(value_2), result_bd = {{0}};

    error = s21_mul_big_decimal(bd_v1, bd_v2, &result_bd);
    if (!error) {
      int conv_error = s21_check_big_to_decimal(result_bd);
      if (conv_error || result_scale > MAX_SCALE) {
        error = s21_reduce_scale(&result_bd, &result_scale, result_sign);
      }
    }

    if (!error) {
      if (s21_check_big_to_decimal(result_bd)) {
        error = (result_sign ? NUMBER_MIN_INF : NUMBER_INF);
      }
    }

    if (!error) {
      s21_big_to_decimal(result_bd, result);
      s21_set_scale(result, result_scale);
    }
  }

  if (!error && !is_decimal_zero) s21_set_sign(result, result_sign);
  return error;
}

int s21_mul_big_decimal(s21_big_decimal value_1, s21_big_decimal value_2,
                        s21_big_decimal *result) {
  int error = OK;
  for (int i = 0; i < BITS_BIG_DECIMAL - 1 && !error; ++i) {
    unsigned long long carry = 0ULL;
    int j = 0;
    for (j = 0; j < BITS_BIG_DECIMAL - 1 && (i + j) < BITS_BIG_DECIMAL - 1;
         ++j) {
      int k = i + j;
      unsigned long long prod = (unsigned long long)value_1.bits[i] *
                                (unsigned long long)value_2.bits[j];
      unsigned long long sum =
          (unsigned long long)result->bits[k] + prod + carry;
      result->bits[k] = (unsigned int)(sum & 0xFFFFFFFFu);
      carry = sum >> 32;
    }
  }

  return error;
}
