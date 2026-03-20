#include "s21_conversion.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  if (!dst) return 1;
  *dst = (s21_decimal){0};
  if (src < 0) {
    s21_set_sign(dst, 1);
    src = -src;
  }
  dst->bits[0] = src;
  return 0;
}