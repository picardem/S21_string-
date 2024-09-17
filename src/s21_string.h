#ifndef S21_STRING
#define S21_STRING

#include <float.h>
#include <math.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define s21_NULL (void *)0
typedef unsigned long s21_size_t;

void *s21_memchr(const void *arr, int c, s21_size_t n);
int s21_memcmp(const void *arr, const void *arr2, s21_size_t n);
void *s21_memcpy(void *destination, const void *source, s21_size_t n);
void *s21_memset(void *destination, int c, s21_size_t n);
void *s21_strncat(char *destination, const char *source, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, size_t n);
char *s21_strncpy(char *destptr, const char *srcptr, s21_size_t num);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errcode);
s21_size_t s21_strlen(const char *str);
void *s21_to_lower(const char *str);
void *s21_to_upper(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);
char *s21_strpbrk(const char *str, const char *sym);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *orig, const char *match);
char *s21_strpbrk(const char *str, const char *sym);
char *s21_strtok(char *str, const char *del);
int s21_sprintf(char *buf, const char *format, ...);
int s21_sscanf(const char *str, const char *format, ...);

#endif