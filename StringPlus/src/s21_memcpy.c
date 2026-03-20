#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *desti = (char *)dest;
  char *source = (char *)src;

  for (s21_size_t i = 0; i < n; i++) {
    desti[i] = source[i];
  }
  return desti;
}
