#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <stdint.h>
#include <stdio.h>

#define BITS_DECIMAL 4
#define BITS_BIG_DECIMAL 8
#define INT_BITS_COUNT 32
#define MAX_SCALE 28

typedef struct {
  unsigned int bits[BITS_DECIMAL];
} s21_decimal;

typedef struct {
  unsigned int bits[BITS_BIG_DECIMAL];
} s21_big_decimal;

enum enum_error {
  OK = 0,
  FALSE = 0,
  NUMBER_INF = 1,
  TRUE = 1,
  CALC_ERROR = 1,
  ERROR_CONVERT = 1,
  NUMBER_MIN_INF = 2,
  DEV_BY_ZERO = 3
};

#endif
