#ifndef S21_CONVERSION_H
#define S21_CONVERSION_H

#include <math.h>
#include <string.h>

#include "../../s21_decimal.h"
#include "../helpers/s21_helpers.h"
#include "../other/s21_other.h"

#define BIG_DECIMAL 192
#define BIGGER_DECIMAL 384

int s21_from_decimal_to_float(s21_decimal src, float *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_int_to_decimal(int src, s21_decimal *dst);

#endif