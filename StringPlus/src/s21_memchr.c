#include "s21_string.h"
void *s21_memchr(const void *str, int c, s21_size_t n) {
  char *temp = (char *)str;
  for (s21_size_t i = 0; i < n; i++) {
    if (*temp == c) return temp;
    temp++;
  }
  return s21_NULL;
}
