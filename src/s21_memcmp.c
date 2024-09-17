#include "s21_string.h"

int s21_memcmp(const void *arr, const void *arr2, s21_size_t n) {
  const unsigned char *ptr1 = (const unsigned char *)arr;
  const unsigned char *ptr2 = (const unsigned char *)arr2;
  int diff = 0;

  for (s21_size_t i = 0; !diff && i < n; i++) {
    diff = ptr1[i] - ptr2[i];
  }
  return diff;
}
