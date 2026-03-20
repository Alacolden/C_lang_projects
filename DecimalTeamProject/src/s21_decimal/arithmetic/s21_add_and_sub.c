#include "../comparison/s21_comparison.h"
#include "../helpers/s21_helpers.h"
#include "s21_arithm.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = OK;
  for (int i = 0; i < 4; i++) result->bits[i] = 0;

  unsigned int scale_v1 = s21_get_scale(value_1),
               scale_v2 = s21_get_scale(value_2);
  unsigned int sign_v1 = s21_get_sign(value_1), sign_v2 = s21_get_sign(value_2),
               result_sign = 0;
  unsigned int result_scale = scale_v1 >= scale_v2 ? scale_v1 : scale_v2;
  unsigned int diff =
      scale_v1 > scale_v2 ? scale_v1 - scale_v2 : scale_v2 - scale_v1;

  s21_big_decimal bd_v1 = s21_decimal_to_big(value_1),
                  bd_v2 = s21_decimal_to_big(value_2), result_bd = {{0}};

  if (scale_v1 < scale_v2) {
    error = (s21_mult_big_by_ten_power(&bd_v1, diff));
  } else if (diff != 0) {
    error = (s21_mult_big_by_ten_power(&bd_v2, diff));
  }

  if (!error) {
    int cmp = s21_compare_big_decimal(bd_v1, bd_v2);
    if (sign_v1 == sign_v2) {
      error = s21_add_big_decimal(bd_v1, bd_v2, &result_bd);
      if (sign_v1 != 0) result_sign = 1;
    } else {
      if (cmp == 1) {
        s21_sub_big_decimal(bd_v1, bd_v2, &result_bd);
        result_sign = sign_v1;
      } else if (cmp == -1) {
        s21_sub_big_decimal(bd_v2, bd_v1, &result_bd);
        result_sign = sign_v2;
      } else {
        result_bd = (s21_big_decimal){{0}};
      }
    }
  }

  if (!error) error = s21_reduce_scale(&result_bd, &result_scale, result_sign);
  if (!error) {
    s21_big_to_decimal(result_bd, result);
    if (s21_is_decimal_zero(*result)) {
      s21_set_sign(result, 0);
      s21_set_scale(result, 0);
    } else {
      s21_set_sign(result, result_sign);
      s21_set_scale(result, result_scale);
    }
  } else if (error == NUMBER_INF && s21_get_sign(*result)) {
    error = NUMBER_MIN_INF;
  }
  return error;
}

int s21_sub(s21_decimal reduced, s21_decimal subtract, s21_decimal *result) {
  int error = OK;
  int sign_subtract = s21_get_sign(subtract);
  s21_set_sign(&subtract, !sign_subtract);
  error = s21_add(reduced, subtract, result);

  return error;
}