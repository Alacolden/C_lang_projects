#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  int i = 0;
  char *s1 = (char *)str1;
  char *s2 = (char *)str2;
  int len = s21_strlen(s2);
  char *res = s21_NULL;
  int flag = 0;
  while (*s1 != '\0' && flag == 0) {
    for (i = 0; i <= len; i++) {
      if (s2[i] == *s1) {
        flag = 1;
        res = s1;
      }
    }
    s1++;
  }

  return res;
}