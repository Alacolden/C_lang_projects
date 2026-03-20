#include "s21_string.h"
s21_size_t s21_strlen(const char *str) {
  long long int i = 0;
  while (*str != '\0') {
    str++;
    i += 1;
  }
  return i;
}
