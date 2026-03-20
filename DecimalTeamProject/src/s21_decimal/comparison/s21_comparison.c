#include "s21_comparison.h"

#include "../helpers/s21_helpers.h"

int s21_compare_big_decimal(
    s21_big_decimal value_1,
    s21_big_decimal value_2) {  // возвращает рез-т сравнения для value_1
  int result = 0;
  int done = 0;
  for (int i = BITS_BIG_DECIMAL - 2; i >= 0 && !done; i--) {
    if (value_1.bits[i] > value_2.bits[i]) {
      result = 1;
      done = 1;
    } else if (value_1.bits[i] < value_2.bits[i]) {
      result = -1;
      done = 1;
    }
  }
  return result;
}

int s21_is_equal(s21_decimal a, s21_decimal b) {
  if (s21_is_decimal_zero(a) && s21_is_decimal_zero(b)) return TRUE;

  if (s21_get_sign(a) != s21_get_sign(b)) return FALSE;

  s21_decimal na = a, nb = b;

  if (normalize_scales(&na, &nb)) return FALSE;

  return compare_mantissa(na, nb) == 0;
}

int s21_is_less(s21_decimal a, s21_decimal b) {
  int is_zero_a = s21_is_decimal_zero(a);
  int is_zero_b = s21_is_decimal_zero(b);

  if (is_zero_a && is_zero_b) return FALSE;
  if (is_zero_a) return !s21_get_sign(b);
  if (is_zero_b) return s21_get_sign(a);

  int sign_a = s21_get_sign(a);
  int sign_b = s21_get_sign(b);

  if (sign_a != sign_b) {
    return sign_a && !sign_b;
  }

  s21_decimal norm_a = a;
  s21_decimal norm_b = b;
  if (normalize_scales(&norm_a, &norm_b) != 0) {
    return FALSE;
  }

  int cmp = compare_mantissa(norm_a, norm_b);

  if (sign_a) {
    return cmp > 0;
  } else {
    return cmp < 0;
  }
}

int s21_is_less_or_equal(s21_decimal a, s21_decimal b) {
  return s21_is_less(a, b) || s21_is_equal(a, b);
}

int s21_is_greater(s21_decimal a, s21_decimal b) { return s21_is_less(b, a); }

int s21_is_greater_or_equal(s21_decimal a, s21_decimal b) {
  return s21_is_greater(a, b) || s21_is_equal(a, b);
}

int s21_is_not_equal(s21_decimal a, s21_decimal b) {
  return !s21_is_equal(a, b);
}