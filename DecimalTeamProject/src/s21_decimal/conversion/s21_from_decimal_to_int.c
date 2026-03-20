#include <limits.h>

#include "s21_conversion.h"

#define MAX_DECIMAL 79228162514264337593543950335.0f
#define MIN_DECIMAL 1e-28f

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  if (!dst) return 1;

  s21_decimal truncated;
  s21_truncate(src, &truncated);

  if (truncated.bits[1] || truncated.bits[2] || truncated.bits[0] > INT_MAX) {
    return 1;
  }

  *dst = truncated.bits[0];
  if (s21_get_sign(src)) {
    *dst = -(*dst);
  }
  return 0;
}
