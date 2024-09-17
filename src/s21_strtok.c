#include "s21_string.h"

char* s21_strtok(char* str, const char* del) {
  static char* start = s21_NULL;

  if (del == s21_NULL || str == s21_NULL) {
    return s21_NULL;
  }

  if (str != s21_NULL) start = str;

  if (start == s21_NULL) {
    return s21_NULL;
  }

  char* res = start;
  s21_size_t shift = 0;

  while (shift == 0 && res != s21_NULL) {
    shift = s21_strcspn(res, (char*)del);

    if (shift == 0 && res[shift] != '\0') {
      res++;

    } else if (shift == 0 && *res == '\0') {
      res = s21_NULL;
      start = s21_NULL;

    } else if (shift != 0 && *res != '\0') {
      res[shift] = '\0';
      start = res + shift + 1;

    } else {
      start = s21_NULL;
    }
  }

  return res;
}
