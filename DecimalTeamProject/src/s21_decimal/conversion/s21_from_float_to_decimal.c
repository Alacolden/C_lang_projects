#include "s21_conversion.h"

#define MAX_DECIMAL 79228162514264337593543950335.0f
#define MIN_DECIMAL 1e-28f

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  if (!dst) return 1;
  *dst = (s21_decimal){0};

  if (isnan(src) || isinf(src)) return 1;
  if (src == 0.0f) {
    s21_set_sign(dst, (signbit(src) ? 1 : 0));
    return 0;
  }

  if (fabsf(src) > MAX_DECIMAL || fabsf(src) < MIN_DECIMAL) return 1;

  int sign = (src < 0) ? 1 : 0;
  float value = fabsf(src);
  int scale = 0;

  while (value < 1000000.0f && scale < 28) {
    value *= 10.0f;
    scale++;
  }

  uint64_t int_value = (uint64_t)roundf(value);

  if (int_value > 0xFFFFFFFFFFFFFFFFULL) return 1;

  dst->bits[0] = (uint32_t)(int_value & 0xFFFFFFFF);
  if (int_value > 0xFFFFFFFFULL) {
    dst->bits[1] = (uint32_t)((int_value >> 32) & 0xFFFFFFFF);
  }
  s21_set_scale(dst, scale);
  s21_set_sign(dst, sign);

  return 0;
}