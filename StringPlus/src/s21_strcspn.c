#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t i = 0;
  int flag = 0;
  for (; *str1 != '\0'; str1++) {
    const char *string = str2;
    for (; *string != '\0'; string++) {
      if (*str1 == *string) {
        flag = 1;
      }
    }
    if (flag == 1) {
      break;
    }
    i++;
  }
  return i;
}