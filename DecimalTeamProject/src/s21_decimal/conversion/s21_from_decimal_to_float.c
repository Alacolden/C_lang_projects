#include "s21_conversion.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  if (!dst) return 1;
  *dst = 0.0f;

  int scale = s21_get_scale(src);
  int sign = s21_get_sign(src);

  long double value = 0.0;

  value += (long double)(uint32_t)src.bits[0];

  if (src.bits[1]) {
    value += (long double)(uint32_t)src.bits[1] * 4294967296.0L;
  }

  if (src.bits[2]) {
    value += (long double)(uint32_t)src.bits[2] * 18446744073709551616.0L;
  }

  if (scale > 0) {
    long double divisor = 1.0L;
    for (int i = 0; i < scale; i++) {
      divisor *= 10.0L;
    }
    value /= divisor;
  }

  *dst = sign ? -(float)value : (float)value;
  return 0;
}