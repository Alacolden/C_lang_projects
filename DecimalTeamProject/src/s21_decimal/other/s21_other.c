#include "s21_other.h"

#include "../arithmetic/s21_arithm.h"
#include "../helpers/s21_helpers.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int remainder = 0;
  return s21_truncate_with_remainder(value, result, &remainder);
}

int s21_floor(s21_decimal value, s21_decimal *result) {
  int remainder = 0;
  int error = s21_truncate_with_remainder(value, result, &remainder);

  if (!error) {
    int sign = s21_get_sign(value);
    if (sign && remainder != 0) {
      s21_decimal one = {{1, 0, 0, 0}};
      s21_set_sign(&one, 1);
      s21_add(*result, one, result);
    }
  }

  return error;
}

int s21_round(s21_decimal value, s21_decimal *result) {
  int remainder = 0;
  int error = s21_truncate_with_remainder(value, result, &remainder);

  if (!error) {
    int sign = s21_get_sign(value);
    if (remainder >= 5) {
      s21_decimal one = {{1, 0, 0, 0}};
      if (sign) s21_set_sign(&one, 1);
      s21_add(*result, one, result);
    }
  }

  return error;
}

int s21_negate(s21_decimal value, s21_decimal *result) {
  int error = OK;
  if (!result) error = CALC_ERROR;

  if (!error) {
    *result = value;
    if (!s21_is_decimal_zero(value)) {
      s21_set_sign(result, !s21_get_sign(value));
    }
  }
  return error;
}

int s21_truncate_with_remainder(s21_decimal value, s21_decimal *result,
                                int *remainder) {
  int error = OK;
  if (!result) error = CALC_ERROR;

  if (!error) {
    unsigned int sign = s21_get_sign(value);
    unsigned int scale = s21_get_scale(value);

    if (scale > MAX_SCALE) {
      for (int i = 0; i < BITS_DECIMAL; i++) result->bits[i] = 0;
    } else if (scale == 0) {
      *result = value;
    } else {
      s21_big_decimal bd = s21_decimal_to_big(value);
      for (unsigned int i = 0; i < scale; i++) {
        *remainder = s21_div_big_by_ten(&bd);
      }
      s21_big_to_decimal(bd, result);
      s21_set_scale(result, 0);
      s21_set_sign(result, sign);
    }
  }

  return error;
}
