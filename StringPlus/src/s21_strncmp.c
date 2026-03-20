#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  char *string1 = (char *)str1;
  char *string2 = (char *)str2;

  for (s21_size_t i = 0; i < n; i++) {
    if (string1[i] != string2[i]) return string1[i] - string2[i];
  }
  return 0;
}
