#include "s21_string.h"

void *s21_memset(void *destination, int c, s21_size_t n) {
  if (destination == s21_NULL || n < 0 || n > sizeof(destination))
    return s21_NULL;
  unsigned char *ptr1 = (unsigned char *)destination;
  s21_size_t i = 0;
  char cc = (char)c;
  for (; i < n; i++) {
    ptr1[i] = cc;
  }
  return destination;
}