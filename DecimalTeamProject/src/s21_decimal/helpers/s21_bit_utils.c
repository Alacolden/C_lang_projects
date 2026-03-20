#include "s21_helpers.h"

int s21_get_scale(s21_decimal value) {
  int scale = (value.bits[3] >> 16) & 0xFF;
  return scale;
}

void s21_set_scale(s21_decimal *value, unsigned int scale) {
  if (scale > 28) return;
  value->bits[3] &= ~(0xFF << 16);
  value->bits[3] |= (scale << 16);
}

int s21_get_sign(s21_decimal value) { return (value.bits[3] >> 31) & 1u; }

void s21_set_sign(s21_decimal *value, unsigned int sign) {
  if (sign > 1) return;
  value->bits[3] &= ~(1u << 31);
  value->bits[3] |= (sign << 31);
}

void s21_set_big_bit(s21_big_decimal *v, unsigned int index, int bit) {
  unsigned int word = index / 32u;
  unsigned int offset = index % 32u;
  if ((int)word > BITS_BIG_DECIMAL - 2) return;
  if (bit)
    v->bits[word] |= (1u << offset);
  else
    v->bits[word] &= ~(1u << offset);
}