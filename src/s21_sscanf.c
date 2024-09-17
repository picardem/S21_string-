#include "s21_string.h"

int my_isdigit(int c) { return c >= '0' && c <= '9'; }

int my_isxdigit(int c) {
  return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') ||
         (c >= 'A' && c <= 'F');
}

int my_isspace(int c) {
  return c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' ||
         c == '\r';
}

void skip_whitespace(const char **str) {
  while (my_isspace(**str)) {
    (*str)++;
  }
}

int read_int(const char **str, int *value) {
  int sign = 1;
  if (**str == '-') {
    sign = -1;
    (*str)++;
  }
  int num = 0;
  while (my_isdigit(**str)) {
    num = num * 10 + (**str - '0');
    (*str)++;
  }
  *value = num * sign;
  return 1;
}

int read_short_int(const char **str, short int *value) {
  int sign = 1;
  if (**str == '-') {
    sign = -1;
    (*str)++;
  }
  short int num = 0;
  while (my_isdigit(**str)) {
    num = num * 10 + (**str - '0');
    (*str)++;
  }
  *value = num * sign;
  return 1;
}

int read_long_int(const char **str, long int *value) {
  int sign = 1;
  if (**str == '-') {
    sign = -1;
    (*str)++;
  }
  long int num = 0;
  while (my_isdigit(**str)) {
    num = num * 10 + (**str - '0');
    (*str)++;
  }
  *value = num * sign;
  return 1;
}

int read_string(const char **str, char *buffer, int width) {
  int count = 0;
  while (**str && !my_isspace(**str) && (width == -1 || count < width)) {
    *buffer++ = **str;
    (*str)++;
    count++;
  }
  *buffer = '\0';
  return 1;
}

int read_wide_string(const char **str, wchar_t *buffer, int width) {
  int count = 0;
  while (**str && !my_isspace(**str) && (width == -1 || count < width)) {
    *buffer++ = (wchar_t) * *str;
    (*str)++;
    count++;
  }
  *buffer = L'\0';
  return 1;
}

int read_char(const char **str, char *value) {
  *value = **str;
  (*str)++;
  return 1;
}

int read_wide_char(const char **str, wchar_t *value) {
  *value = (wchar_t) * *str;
  (*str)++;
  return 1;
}

int read_float(const char **str, float *value) {
  int sign = 1;
  if (**str == '-') {
    sign = -1;
    (*str)++;
  }
  float num = 0.0;
  while (my_isdigit(**str)) {
    num = num * 10 + (**str - '0');
    (*str)++;
  }
  if (**str == '.') {
    (*str)++;
    float fraction = 0.1;
    while (my_isdigit(**str)) {
      num += (**str - '0') * fraction;
      fraction *= 0.1;
      (*str)++;
    }
  }
  if (**str == 'e' || **str == 'E') {
    (*str)++;
    int exponent_sign = 1;
    if (**str == '-') {
      exponent_sign = -1;
      (*str)++;
    } else if (**str == '+') {
      (*str)++;
    }
    int exponent = 0;
    while (my_isdigit(**str)) {
      exponent = exponent * 10 + (**str - '0');
      (*str)++;
    }
    while (exponent > 0) {
      if (exponent_sign > 0) {
        num *= 10;
      } else {
        num *= 0.1;
      }
      exponent--;
    }
  }
  *value = num * sign;
  return 1;
}

int read_long_double(const char **str, long double *value) {
  int sign = 1;
  if (**str == '-') {
    sign = -1;
    (*str)++;
  }
  long double num = 0.0;
  while (my_isdigit(**str)) {
    num = num * 10 + (**str - '0');
    (*str)++;
  }
  if (**str == '.') {
    (*str)++;
    long double fraction = 0.1;
    while (my_isdigit(**str)) {
      num += (**str - '0') * fraction;
      fraction *= 0.1;
      (*str)++;
    }
  }
  if (**str == 'e' || **str == 'E') {
    (*str)++;
    int exponent_sign = 1;
    if (**str == '-') {
      exponent_sign = -1;
      (*str)++;
    } else if (**str == '+') {
      (*str)++;
    }
    int exponent = 0;
    while (my_isdigit(**str)) {
      exponent = exponent * 10 + (**str - '0');
      (*str)++;
    }
    while (exponent > 0) {
      if (exponent_sign > 0) {
        num *= 10;
      } else {
        num *= 0.1;
      }
      exponent--;
    }
  }
  *value = num * sign;
  return 1;
}

int read_octal(const char **str, unsigned int *value) {
  unsigned int num = 0;
  while (**str && my_isdigit(**str) && **str < '8') {
    num = num * 8 + (**str - '0');
    (*str)++;
  }
  *value = num;
  return 1;
}

int read_short_octal(const char **str, unsigned short int *value) {
  unsigned short int num = 0;
  while (**str && my_isdigit(**str) && **str < '8') {
    num = num * 8 + (**str - '0');
    (*str)++;
  }
  *value = num;
  return 1;
}

int read_long_octal(const char **str, unsigned long int *value) {
  unsigned long int num = 0;
  while (**str && my_isdigit(**str) && **str < '8') {
    num = num * 8 + (**str - '0');
    (*str)++;
  }
  *value = num;
  return 1;
}

int read_hex(const char **str, unsigned int *value) {
  unsigned int num = 0;
  while (**str && my_isxdigit(**str)) {
    if (my_isdigit(**str)) {
      num = num * 16 + (**str - '0');
    } else if (**str >= 'a' && **str <= 'f') {
      num = num * 16 + (**str - 'a' + 10);
    } else if (**str >= 'A' && **str <= 'F') {
      num = num * 16 + (**str - 'A' + 10);
    }
    (*str)++;
  }
  *value = num;
  return 1;
}

int read_short_hex(const char **str, unsigned short int *value) {
  unsigned short int num = 0;
  while (**str && my_isxdigit(**str)) {
    if (my_isdigit(**str)) {
      num = num * 16 + (**str - '0');
    } else if (**str >= 'a' && **str <= 'f') {
      num = num * 16 + (**str - 'a' + 10);
    } else if (**str >= 'A' && **str <= 'F') {
      num = num * 16 + (**str - 'A' + 10);
    }
    (*str)++;
  }
  *value = num;
  return 1;
}

int read_long_hex(const char **str, unsigned long int *value) {
  unsigned long int num = 0;
  while (**str && my_isxdigit(**str)) {
    if (my_isdigit(**str)) {
      num = num * 16 + (**str - '0');
    } else if (**str >= 'a' && **str <= 'f') {
      num = num * 16 + (**str - 'a' + 10);
    } else if (**str >= 'A' && **str <= 'F') {
      num = num * 16 + (**str - 'A' + 10);
    }
    (*str)++;
  }
  *value = num;
  return 1;
}

void read_pointer(const char **str, void **arg) {
  unsigned long long value = 0;
  if (**str == '0' && (*(*str + 1) == 'x' || *(*str + 1) == 'X')) {
    (*str) += 2;  // Skip '0x' or '0X'
    while (**str && my_isxdigit(**str)) {
      value = value * 16 + (**str <= '9' ? **str - '0' : **str - 'a' + 10);
      (*str)++;
    }
  }
  *arg = (void *)value;
}

int s21_sscanf(const char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);

  int count = 0;
  while (*format) {
    if (*format == '%') {
      format++;
      int width = -1;
      int length = 0;    // 0: none, 1: h, 2: l
      int suppress = 0;  // 0: assign, 1: suppress

      if (*format == '*') {
        suppress = 1;
        format++;
      }

      if (my_isdigit(*format)) {
        width = 0;
        while (my_isdigit(*format)) {
          width = width * 10 + (*format - '0');
          format++;
        }
      }
      if (*format == 'h') {
        length = 1;
        format++;
      } else if (*format == 'l') {
        length = 2;
        format++;
      }
      if (*format == 'd' || *format == 'i') {
        skip_whitespace(&str);
        if (length == 1) {
          if (!suppress) {
            short int *arg = va_arg(args, short int *);
            read_short_int(&str, arg);
          } else {
            short int temp;
            read_short_int(&str, &temp);
          }
        } else if (length == 2) {
          if (!suppress) {
            long int *arg = va_arg(args, long int *);
            read_long_int(&str, arg);
          } else {
            long int temp;
            read_long_int(&str, &temp);
          }
        } else {
          if (!suppress) {
            int *arg = va_arg(args, int *);
            read_int(&str, arg);
          } else {
            int temp;
            read_int(&str, &temp);
          }
        }
        if (!suppress) count++;
      } else if (*format == 's') {
        skip_whitespace(&str);
        if (length == 2) {
          if (!suppress) {
            char *arg = va_arg(args, char *);
            read_string(&str, arg, width);
          } else {
            char temp[256];
            read_string(&str, temp, width);
          }
        } else {
          if (!suppress) {
            char *arg = va_arg(args, char *);
            read_string(&str, arg, width);
          } else {
            char temp[256];
            read_string(&str, temp, width);
          }
        }
        if (!suppress) count++;
      } else if (*format == 'c') {
        if (length == 2) {
          if (!suppress) {
            wchar_t *arg = va_arg(args, wchar_t *);
            read_wide_char(&str, arg);
          } else {
            wchar_t temp;
            read_wide_char(&str, &temp);
          }
        } else {
          if (!suppress) {
            char *arg = va_arg(args, char *);
            read_char(&str, arg);
          } else {
            char temp;
            read_char(&str, &temp);
          }
        }
        if (!suppress) count++;
      } else if (*format == 'e' || *format == 'E' || *format == 'f' ||
                 *format == 'g' || *format == 'G') {
        skip_whitespace(&str);
        if (!suppress) {
          float *arg = va_arg(args, float *);
          read_float(&str, arg);
        } else {
          float temp;
          read_float(&str, &temp);
        }
        if (!suppress) count++;
      } else if (*format == 'o') {
        skip_whitespace(&str);
        if (length == 1) {
          if (!suppress) {
            unsigned short int *arg = va_arg(args, unsigned short int *);
            read_short_octal(&str, arg);
          } else {
            unsigned short int temp;
            read_short_octal(&str, &temp);
          }
        } else if (length == 2) {
          if (!suppress) {
            unsigned long int *arg = va_arg(args, unsigned long int *);
            read_long_octal(&str, arg);
          } else {
            unsigned long int temp;
            read_long_octal(&str, &temp);
          }
        } else {
          if (!suppress) {
            unsigned int *arg = va_arg(args, unsigned int *);
            read_octal(&str, arg);
          } else {
            unsigned int temp;
            read_octal(&str, &temp);
          }
        }
        if (!suppress) count++;
      } else if (*format == 'u') {
        skip_whitespace(&str);
        if (length == 1) {
          if (!suppress) {
            unsigned short int *arg = va_arg(args, unsigned short int *);
            read_short_int(&str, (short int *)arg);
          } else {
            unsigned short int temp;
            read_short_int(&str, (short int *)&temp);
          }
        } else if (length == 2) {
          if (!suppress) {
            unsigned long int *arg = va_arg(args, unsigned long int *);
            read_long_int(&str, (long int *)arg);
          } else {
            unsigned long int temp;
            read_long_int(&str, (long int *)&temp);
          }
        } else {
          if (!suppress) {
            unsigned int *arg = va_arg(args, unsigned int *);
            read_int(&str, (int *)arg);
          } else {
            unsigned int temp;
            read_int(&str, (int *)&temp);
          }
        }
        if (!suppress) count++;
      } else if (*format == 'x' || *format == 'X') {
        skip_whitespace(&str);
        if (length == 1) {
          if (!suppress) {
            unsigned short int *arg = va_arg(args, unsigned short int *);
            read_short_hex(&str, arg);
          } else {
            unsigned short int temp;
            read_short_hex(&str, &temp);
          }
        } else if (length == 2) {
          if (!suppress) {
            unsigned long int *arg = va_arg(args, unsigned long int *);
            read_long_hex(&str, arg);
          } else {
            unsigned long int temp;
            read_long_hex(&str, &temp);
          }
        } else {
          if (!suppress) {
            unsigned int *arg = va_arg(args, unsigned int *);
            read_hex(&str, arg);
          } else {
            unsigned int temp;
            read_hex(&str, &temp);
          }
        }
        if (!suppress) count++;
      } else if (*format == 'p') {
        skip_whitespace(&str);
        if (!suppress) {
          void **arg = va_arg(args, void **);
          read_pointer(&str, arg);
        } else {
          void *temp;
          read_pointer(&str, &temp);
        }
        if (!suppress) count++;
      } else if (*format == 'n') {
        int *arg = va_arg(args, int *);
        *arg = str - (const char *)str;
        count++;
      } else if (*format == 'L' &&
                 (*(format + 1) == 'e' || *(format + 1) == 'E' ||
                  *(format + 1) == 'f' || *(format + 1) == 'g' ||
                  *(format + 1) == 'G')) {
        skip_whitespace(&str);
        if (!suppress) {
          long double *arg = va_arg(args, long double *);
          read_long_double(&str, arg);
        } else {
          long double temp;
          read_long_double(&str, &temp);
        }
        if (!suppress) count++;
        format++;
      } else if (*format == '%') {
        if (*str == '%') {
          str++;
        } else {
          break;
        }
      }
    } else {
      if (*str == *format) {
        str++;
      } else {
        break;
      }
    }
    format++;
  }

  va_end(args);
  return count;
}