#include "../comparison/s21_comparison.h"
#include "../helpers/s21_helpers.h"
#include "s21_arithm.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = OK;
  for (int i = 0; i < BITS_DECIMAL; i++) result->bits[i] = 0;

  if (s21_is_decimal_zero(value_2)) return DEV_BY_ZERO;
  if (s21_is_decimal_zero(value_1)) return OK;

  int result_sign = s21_get_sign(value_1) ^ s21_get_sign(value_2);
  int result_scale = (int)s21_get_scale(value_1) - (int)s21_get_scale(value_2);
  s21_big_decimal bd_v1 = s21_decimal_to_big(value_1),
                  bd_v2 = s21_decimal_to_big(value_2), result_bd = {{0}};

  while (result_scale < 0 && !error) {
    error = s21_mult_big_by_ten_power(&bd_v1, 1);
    result_scale++;
  }
  if (error) return result_sign ? NUMBER_MIN_INF : NUMBER_INF;

  s21_big_decimal rem = s21_div_big(bd_v1, bd_v2, &result_bd);

  while (!s21_is_big_decimal_zero(rem) && result_scale < MAX_SCALE && !error) {
    s21_mult_big_by_ten_power(&result_bd, 1);
    s21_mult_big_by_ten_power(&rem, 1);
    result_scale++;
    if (s21_compare_big_decimal(rem, bd_v2) >= 0) {
      s21_big_decimal temp_digit = {{0}};
      rem = s21_div_big(rem, bd_v2, &temp_digit);
      error = s21_add_big_decimal(result_bd, temp_digit, &result_bd);
    }
  }

  if (!s21_is_big_decimal_zero(rem)) {
    s21_big_decimal doubled = rem;
    s21_add_big_decimal(doubled, rem, &doubled);
    int cmp = s21_compare_big_decimal(doubled, bd_v2);
    if (cmp > 0 || (cmp == 0 && (result_bd.bits[0] & 1))) {
      error = s21_add_one_to_big(&result_bd);
    }
  }

  if (error) return result_sign ? NUMBER_MIN_INF : NUMBER_INF;

  if (s21_check_big_to_decimal(result_bd) || result_scale > MAX_SCALE) {
    int red_err = s21_reduce_scale(&result_bd, (unsigned int *)&result_scale,
                                   result_sign);
    if (red_err != 0) return red_err;
  }

  if (s21_is_big_decimal_zero(result_bd)) {
    if (s21_is_minimal_decimal(value_1)) return NUMBER_MIN_INF;
    return OK;
  }

  s21_big_to_decimal(result_bd, result);
  s21_set_scale(result, result_scale);
  s21_set_sign(result, result_sign);

  return OK;
}
int s21_is_minimal_decimal(s21_decimal v) {
  return (v.bits[0] == 1u && v.bits[1] == 0u && v.bits[2] == 0u &&
          (s21_get_scale(v) == 28));
}

int s21_big_bit_length(const s21_big_decimal *v) {
  for (int i = BITS_BIG_DECIMAL - 2; i >= 0; --i) {
    if (v->bits[i] != 0u) {
      unsigned int word = v->bits[i];
      int pos = 32;
      while ((word >> --pos) == 0u) {
        if (pos == 0) break;
      }
      return i * 32 + (pos + 1);
    }
  }
  return 0;
}

void s21_shl_big(s21_big_decimal *v, unsigned int n) {
  if (n == 0) return;
  int maxw = BITS_BIG_DECIMAL - 2;
  unsigned int word_shift = n / 32u;
  unsigned int bit_shift = n % 32u;

  if (word_shift) {
    for (int i = maxw; i >= 0; --i) {
      unsigned int src =
          (int)i - (int)word_shift >= 0 ? v->bits[i - word_shift] : 0u;
      v->bits[i] = src;
    }
  }

  if (bit_shift) {
    unsigned int carry = 0u;
    for (int i = 0; i <= maxw; ++i) {
      unsigned long long cur =
          ((unsigned long long)v->bits[i] << bit_shift) | carry;
      v->bits[i] = (unsigned int)(cur & 0xFFFFFFFFu);
      carry = (unsigned int)(cur >> 32);
    }
  }
}

void s21_shr_big(s21_big_decimal *v, unsigned int n) {
  if (n == 0) return;
  int maxw = BITS_BIG_DECIMAL - 2;
  unsigned int bit_shift = n % 32u;

  if (bit_shift) {
    unsigned int carry = 0u;
    for (int i = maxw; i >= 0; --i) {
      unsigned long long cur = ((unsigned long long)carry << 32) | v->bits[i];
      v->bits[i] = (unsigned int)(cur >> bit_shift);
      carry = (unsigned int)(cur & ((1u << bit_shift) - 1u));
      if (i == 0) break;
    }
  }
}

s21_big_decimal s21_div_big(s21_big_decimal dividend, s21_big_decimal divisor,
                            s21_big_decimal *quotient) {
  s21_big_decimal q = {{0}};
  s21_big_decimal r = {{0}};

  if (s21_compare_big_decimal(dividend, divisor) < 0) {
    if (quotient) *quotient = q;
    return dividend;
  }

  int len_div = s21_big_bit_length(&dividend);
  int len_dvr = s21_big_bit_length(&divisor);
  int shift = len_div - len_dvr;

  s21_big_decimal d_shift = divisor;
  if (shift > 0) s21_shl_big(&d_shift, (unsigned int)shift);

  r = dividend;
  for (int s = shift; s >= 0; --s) {
    if (s21_compare_big_decimal(r, d_shift) >= 0) {
      s21_big_decimal tmp = {{0}};
      s21_sub_big_decimal(r, d_shift, &tmp);
      r = tmp;
      s21_set_big_bit(&q, (unsigned int)s, 1);
    }
    if (s > 0) s21_shr_big(&d_shift, 1);
  }

  if (quotient) *quotient = q;
  return r;
}
