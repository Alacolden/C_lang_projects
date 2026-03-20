#include "s21_helpers.h"

s21_big_decimal s21_decimal_to_big(s21_decimal value) {
  s21_big_decimal bd = {{0}};
  bd.bits[0] = value.bits[0];
  bd.bits[1] = value.bits[1];
  bd.bits[2] = value.bits[2];
  bd.bits[7] = value.bits[3];
  return bd;
}

void s21_big_to_decimal(s21_big_decimal big, s21_decimal *decimal) {
  decimal->bits[0] = big.bits[0];
  decimal->bits[1] = big.bits[1];
  decimal->bits[2] = big.bits[2];
  decimal->bits[3] = big.bits[7];
}

int s21_check_big_to_decimal(s21_big_decimal value) {
  int error = 0;
  for (int i = 3; i < BITS_BIG_DECIMAL - 1; i++) {
    if (value.bits[i] != 0u) {
      error = 1;
      break;
    }
  }
  return error;
}

int s21_mult_big_by_ten_power(s21_big_decimal *value, unsigned int power) {
  int error = 0;

  for (unsigned int p = 0; p < power; p++) {
    unsigned long long carry = 0;
    for (int i = 0; i < BITS_BIG_DECIMAL - 1; i++) {
      unsigned long long temp = (unsigned long long)value->bits[i] * 10 + carry;
      value->bits[i] = (unsigned int)(temp & 0xFFFFFFFF);
      carry = temp >> 32;
    }
    if (carry != 0) {
      error = 1;
      break;
    }
  }

  return error;
}
int s21_add_big_decimal(s21_big_decimal value_1, s21_big_decimal value_2,
                        s21_big_decimal *result) {
  int error = 0;
  unsigned long long carry = 0, temp = 0;
  for (int i = 0; i < BITS_BIG_DECIMAL - 1; i++) {
    temp = (unsigned long long)value_1.bits[i] +
           (unsigned long long)value_2.bits[i] + carry;
    result->bits[i] = (unsigned int)temp & 0xFFFFFFFFu;
    carry = temp >> 32;
  }

  if (carry != 0) {
    error = 1;
  }
  return error;
}

void s21_sub_big_decimal(s21_big_decimal value_1, s21_big_decimal value_2,
                         s21_big_decimal *result) {
  int borrow = 0;
  long long temp = 0;
  for (int i = 0; i < BITS_BIG_DECIMAL - 1; i++) {
    temp = (long long)value_1.bits[i] - (long long)value_2.bits[i] - borrow;
    if (temp < 0) {
      temp += (1ULL << 32);
      borrow = 1;
    } else {
      borrow = 0;
    }
    result->bits[i] = temp & 0xFFFFFFFF;
  }
}

int s21_is_decimal_zero(s21_decimal value) {
  return value.bits[0] == 0 && value.bits[1] == 0 && value.bits[2] == 0;
}

int s21_is_big_decimal_zero(s21_big_decimal value) {
  int result = 1;
  for (int i = 0; i < BITS_BIG_DECIMAL - 1; i++) {
    if (value.bits[i] != 0) {
      result = 0;
      break;
    }
  }
  return result;
}

void s21_value_copy(s21_decimal value, s21_decimal *result) {
  for (int i = 0; i < BITS_DECIMAL; i++) {
    result->bits[i] = value.bits[i];
  }
}

int s21_is_decimal_one(s21_decimal value, unsigned int scale) {
  return value.bits[0] == 1 && value.bits[1] == 0 && value.bits[2] == 0 &&
         scale == 0;
}

int s21_div_big_by_ten(s21_big_decimal *value) {
  unsigned long long carry = 0ULL;
  for (int i = BITS_BIG_DECIMAL - 2; i >= 0; i--) {
    unsigned long long temp = (carry << 32) | value->bits[i];
    value->bits[i] = (unsigned int)(temp / 10ULL);
    carry = temp % 10ULL;
  }
  return (int)carry;
}

int s21_add_one_to_big(s21_big_decimal *value) {
  unsigned long long carry = 1ULL;
  for (int i = 0; i < BITS_BIG_DECIMAL - 1; i++) {
    unsigned long long temp = (unsigned long long)(value->bits[i]) + carry;
    value->bits[i] = (unsigned int)(temp & 0xFFFFFFFFu);
    carry = temp >> 32;
    if (!carry) break;
  }

  return carry ? 1 : 0;
}

int s21_big_rounding(s21_big_decimal *value, unsigned int *scale) {
  int error = 0;
  if (*scale == 0u) {
    error = 1;
  } else {
    int remains = s21_div_big_by_ten(value);
    if ((remains > 5) || (remains == 5 && (value->bits[0] & 1u))) {
      error = s21_add_one_to_big(value);
    }
    if (!error) (*scale)--;
  }

  return error;
}

int s21_reduce_scale(s21_big_decimal *result_bd, unsigned int *result_scale,
                     unsigned int result_sign) {
  int error = 1;
  int conv_error = s21_check_big_to_decimal(*result_bd);

  if (!conv_error && *result_scale <= MAX_SCALE) {
    error = 0;
  } else {
    while (*result_scale > 0 && (conv_error || *result_scale > MAX_SCALE)) {
      int reduced = s21_big_rounding(result_bd, result_scale);
      if (reduced) {
        error = 1;
        break;
      }
      conv_error = s21_check_big_to_decimal(*result_bd);
      if (!conv_error) error = 0;
    }
  }

  if (s21_check_big_to_decimal(*result_bd) == 0 && *result_scale <= MAX_SCALE) {
    error = 0;
  } else {
    error = result_sign ? 2 : 1;
  }

  return error;
}

int normalize_scales(s21_decimal *a, s21_decimal *b) {
  unsigned int scale_a = (unsigned int)s21_get_scale(*a);
  unsigned int scale_b = (unsigned int)s21_get_scale(*b);

  if (scale_a == scale_b) return 0;

  if (scale_a < scale_b) {
    s21_big_decimal big_a = s21_decimal_to_big(*a);
    unsigned int diff = scale_b - scale_a;
    if (s21_mult_big_by_ten_power(&big_a, diff) != 0) {
      while (diff > 0) {
        s21_big_rounding(&big_a, &scale_a);
        diff--;
      }
    }
    big_to_decimal(big_a, a, scale_b);
  } else {
    s21_big_decimal big_b = s21_decimal_to_big(*b);
    unsigned int diff = scale_a - scale_b;
    if (s21_mult_big_by_ten_power(&big_b, diff) != 0) {
      while (diff > 0) {
        s21_big_rounding(&big_b, &scale_b);
        diff--;
      }
    }
    big_to_decimal(big_b, b, scale_a);
  }
  return 0;
}
int compare_mantissa(s21_decimal a, s21_decimal b) {
  s21_big_decimal ba = s21_decimal_to_big(a);
  s21_big_decimal bb = s21_decimal_to_big(b);

  int scale_a = s21_get_scale(a);
  int scale_b = s21_get_scale(b);

  if (scale_a < scale_b)
    s21_mult_big_by_ten_power(&ba, scale_b - scale_a);
  else if (scale_b < scale_a)
    s21_mult_big_by_ten_power(&bb, scale_a - scale_b);

  for (int i = BITS_BIG_DECIMAL - 2; i >= 0; i--) {
    if (ba.bits[i] > bb.bits[i]) return 1;
    if (ba.bits[i] < bb.bits[i]) return -1;
  }
  return 0;
}
int left_shift(s21_decimal *value, int shift) {
  if (shift < 0 || shift > 96) return 1;
  if (shift == 0) return 0;

  uint64_t carry = 0;

  for (int i = 0; i < 3; i++) {
    uint64_t bits = (uint64_t)value->bits[i];

    bits = (bits << shift) | carry;
    value->bits[i] = (int)(bits & 0xFFFFFFFF);

    carry = bits >> 32;
  }

  return (carry != 0) ? 1 : 0;
}

int big_to_decimal(s21_big_decimal big, s21_decimal *result, int scale) {
  for (int i = 3; i < BITS_BIG_DECIMAL; i++) {
    if (big.bits[i] != 0) return 1;
  }

  for (int i = 0; i < 3; i++) {
    result->bits[i] = big.bits[i];
  }

  int sign = s21_get_sign(*result);
  s21_set_scale(result, scale);
  if (sign) {
    result->bits[3] |= (1u << 31);
  }

  return 0;
}