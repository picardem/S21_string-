
#include "s21_test.h"

START_TEST(test_sscanf_c) {
  char buffer[100];
  char buffer_orig[100];
  char c;
  char c_orig;
  strcpy(buffer, "A");
  strcpy(buffer_orig, "A");
  ck_assert_int_eq(s21_sscanf(buffer, "%c", &c),
                   sscanf(buffer_orig, "%c", &c_orig));
  ck_assert_int_eq(c, c_orig);
}
END_TEST

START_TEST(test_sscanf_d) {
  char buffer[100];
  char buffer_orig[100];
  int d;
  int d_orig;
  strcpy(buffer, "123");
  strcpy(buffer_orig, "123");
  ck_assert_int_eq(s21_sscanf(buffer, "%d", &d),
                   sscanf(buffer_orig, "%d", &d_orig));
  ck_assert_int_eq(d, d_orig);
}
END_TEST

START_TEST(test_sscanf_f) {
  char buffer[100];
  char buffer_orig[100];
  float f;
  float f_orig;
  strcpy(buffer, "123.456");
  strcpy(buffer_orig, "123.456");
  ck_assert_int_eq(s21_sscanf(buffer, "%f", &f),
                   sscanf(buffer_orig, "%f", &f_orig));
  ck_assert_float_eq(f, f_orig);
}
END_TEST

START_TEST(test_sscanf_s) {
  char buffer[100];
  char buffer_orig[100];
  char s[100];
  char s_orig[100];
  strcpy(buffer, "Hello World");
  strcpy(buffer_orig, "Hello World");
  ck_assert_int_eq(s21_sscanf(buffer, "%s", s),
                   sscanf(buffer_orig, "%s", s_orig));
  ck_assert_str_eq(s, s_orig);
}
END_TEST

START_TEST(test_sscanf_u) {
  char buffer[100];
  char buffer_orig[100];
  unsigned int u;
  unsigned int u_orig;
  strcpy(buffer, "12345");
  strcpy(buffer_orig, "12345");
  ck_assert_int_eq(s21_sscanf(buffer, "%u", &u),
                   sscanf(buffer_orig, "%u", &u_orig));
  ck_assert_uint_eq(u, u_orig);
}
END_TEST

START_TEST(test_sscanf_percent) {
  char buffer[100];
  char buffer_orig[100];
  int percent;
  int percent_orig;
  strcpy(buffer, "100%");
  strcpy(buffer_orig, "100%");
  ck_assert_int_eq(s21_sscanf(buffer, "%d%%", &percent),
                   sscanf(buffer_orig, "%d%%", &percent_orig));
  ck_assert_int_eq(percent, percent_orig);
}
END_TEST

START_TEST(test_sscanf_g) {
  char buffer[100];
  char buffer_orig[100];
  float g;
  float g_orig;
  strcpy(buffer, "123.456");
  strcpy(buffer_orig, "123.456");
  ck_assert_int_eq(s21_sscanf(buffer, "%g", &g),
                   sscanf(buffer_orig, "%g", &g_orig));
  ck_assert_float_eq(g, g_orig);
}
END_TEST

START_TEST(test_sscanf_G) {
  char buffer[100];
  char buffer_orig[100];
  float G;
  float G_orig;
  strcpy(buffer, "123.456");
  strcpy(buffer_orig, "123.456");
  ck_assert_int_eq(s21_sscanf(buffer, "%G", &G),
                   sscanf(buffer_orig, "%G", &G_orig));
  ck_assert_float_eq(G, G_orig);
}
END_TEST

START_TEST(test_sscanf_e) {
  char buffer[100];
  char buffer_orig[100];
  float e;
  float e_orig;
  strcpy(buffer, "1.234e5");
  strcpy(buffer_orig, "1.234e5");
  ck_assert_int_eq(s21_sscanf(buffer, "%e", &e),
                   sscanf(buffer_orig, "%e", &e_orig));
  ck_assert_float_eq(e, e_orig);
}
END_TEST

START_TEST(test_sscanf_E) {
  char buffer[100];
  char buffer_orig[100];
  float E;
  float E_orig;
  strcpy(buffer, "1.234E5");
  strcpy(buffer_orig, "1.234E5");
  ck_assert_int_eq(s21_sscanf(buffer, "%E", &E),
                   sscanf(buffer_orig, "%E", &E_orig));
  ck_assert_float_eq(E, E_orig);
}
END_TEST

START_TEST(test_sscanf_x) {
  char buffer[100];
  char buffer_orig[100];
  unsigned int x;
  unsigned int x_orig;
  strcpy(buffer, "1a2b3c");
  strcpy(buffer_orig, "1a2b3c");
  ck_assert_int_eq(s21_sscanf(buffer, "%x", &x),
                   sscanf(buffer_orig, "%x", &x_orig));
  ck_assert_uint_eq(x, x_orig);
}
END_TEST

START_TEST(test_sscanf_X) {
  char buffer[100];
  char buffer_orig[100];
  unsigned int X;
  unsigned int X_orig;
  strcpy(buffer, "1A2B3C");
  strcpy(buffer_orig, "1A2B3C");
  ck_assert_int_eq(s21_sscanf(buffer, "%X", &X),
                   sscanf(buffer_orig, "%X", &X_orig));
  ck_assert_uint_eq(X, X_orig);
}
END_TEST

START_TEST(test_sscanf_o) {
  char buffer[100];
  char buffer_orig[100];
  unsigned int o;
  unsigned int o_orig;
  strcpy(buffer, "12345");
  strcpy(buffer_orig, "12345");
  ck_assert_int_eq(s21_sscanf(buffer, "%o", &o),
                   sscanf(buffer_orig, "%o", &o_orig));
  ck_assert_uint_eq(o, o_orig);
}
END_TEST

START_TEST(test_sscanf_p) {
  char buffer[100];
  char buffer_orig[100];
  void *p;
  void *p_orig;
  strcpy(buffer, "0x7ffeeb87b6c0");
  strcpy(buffer_orig, "0x7ffeeb87b6c0");
  ck_assert_int_eq(s21_sscanf(buffer, "%p", &p),
                   sscanf(buffer_orig, "%p", &p_orig));
  ck_assert_ptr_eq(p, p_orig);
}
END_TEST

START_TEST(test_sscanf_width) {
  char buffer[100];
  char buffer_orig[100];
  char s[10];
  char s_orig[10];
  strcpy(buffer, "Hello World");
  strcpy(buffer_orig, "Hello World");
  ck_assert_int_eq(s21_sscanf(buffer, "%5s", s),
                   sscanf(buffer_orig, "%5s", s_orig));
  ck_assert_str_eq(s, s_orig);
}
END_TEST

START_TEST(test_sscanf_star) {
  char buffer[100];
  char buffer_orig[100];
  int d;
  int d_orig;
  strcpy(buffer, "123 456");
  strcpy(buffer_orig, "123 456");
  ck_assert_int_eq(s21_sscanf(buffer, "%*d %d", &d),
                   sscanf(buffer_orig, "%*d %d", &d_orig));
  ck_assert_int_eq(d, d_orig);
}
END_TEST

START_TEST(test_sscanf_length_l) {
  char buffer[100];
  char buffer_orig[100];
  long l;
  long l_orig;
  strcpy(buffer, "1234567890");
  strcpy(buffer_orig, "1234567890");
  ck_assert_int_eq(s21_sscanf(buffer, "%ld", &l),
                   sscanf(buffer_orig, "%ld", &l_orig));
  ck_assert_int_eq(l, l_orig);
}
END_TEST

START_TEST(test_sscanf_length_h) {
  char buffer[100];
  char buffer_orig[100];
  short h;
  short h_orig;
  strcpy(buffer, "12345");
  strcpy(buffer_orig, "12345");
  ck_assert_int_eq(s21_sscanf(buffer, "%hd", &h),
                   sscanf(buffer_orig, "%hd", &h_orig));
  ck_assert_int_eq(h, h_orig);
}
END_TEST

START_TEST(test_sscanf_length_L) {
  char buffer[100];
  char buffer_orig[100];
  long double L;
  long double L_orig;
  strcpy(buffer, "123.456");
  strcpy(buffer_orig, "123.456");
  ck_assert_int_eq(s21_sscanf(buffer, "%Lf", &L),
                   sscanf(buffer_orig, "%Lf", &L_orig));
  // ck_assert_ldouble_eq(L, L_orig);
}
END_TEST

// Негативные тесты

START_TEST(test_sscanf_negative_c) {
  char buffer[100];
  char buffer_orig[100];
  char c;
  char c_orig;
  strcpy(buffer, "A");
  strcpy(buffer_orig, "A");
  ck_assert_int_eq(s21_sscanf(buffer, "%c", &c),
                   sscanf(buffer_orig, "%c", &c_orig));
  ck_assert_int_ne(c, c_orig + 1);
}
END_TEST

START_TEST(test_sscanf_negative_d) {
  char buffer[100];
  char buffer_orig[100];
  int d;
  int d_orig;
  strcpy(buffer, "123");
  strcpy(buffer_orig, "123");
  ck_assert_int_eq(s21_sscanf(buffer, "%d", &d),
                   sscanf(buffer_orig, "%d", &d_orig));
  ck_assert_int_ne(d, d_orig + 1);
}
END_TEST

START_TEST(test_sscanf_negative_f) {
  char buffer[100];
  char buffer_orig[100];
  float f;
  float f_orig;
  strcpy(buffer, "123.456");
  strcpy(buffer_orig, "123.456");
  ck_assert_int_eq(s21_sscanf(buffer, "%f", &f),
                   sscanf(buffer_orig, "%f", &f_orig));
  ck_assert_float_ne(f, f_orig + 1.0);
}
END_TEST

START_TEST(test_sscanf_negative_s) {
  char buffer[100];
  char buffer_orig[100];
  char s[100];
  char s_orig[100];
  strcpy(buffer, "Hello World");
  strcpy(buffer_orig, "Hello World");
  ck_assert_int_eq(s21_sscanf(buffer, "%s", s),
                   sscanf(buffer_orig, "%s", s_orig));
  ck_assert_str_ne(s, "Hello World!");
}
END_TEST

START_TEST(test_sscanf_negative_u) {
  char buffer[100];
  char buffer_orig[100];
  unsigned int u;
  unsigned int u_orig;
  strcpy(buffer, "12345");
  strcpy(buffer_orig, "12345");
  ck_assert_int_eq(s21_sscanf(buffer, "%u", &u),
                   sscanf(buffer_orig, "%u", &u_orig));
  ck_assert_uint_ne(u, u_orig + 1);
}
END_TEST

START_TEST(test_sscanf_negative_percent) {
  char buffer[100];
  char buffer_orig[100];
  int percent;
  int percent_orig;
  strcpy(buffer, "100%");
  strcpy(buffer_orig, "100%");
  ck_assert_int_eq(s21_sscanf(buffer, "%d%%", &percent),
                   sscanf(buffer_orig, "%d%%", &percent_orig));
  ck_assert_int_ne(percent, percent_orig + 1);
}
END_TEST

START_TEST(test_sscanf_negative_g) {
  char buffer[100];
  char buffer_orig[100];
  float g;
  float g_orig;
  strcpy(buffer, "123.456");
  strcpy(buffer_orig, "123.456");
  ck_assert_int_eq(s21_sscanf(buffer, "%g", &g),
                   sscanf(buffer_orig, "%g", &g_orig));
  ck_assert_float_ne(g, g_orig + 1.0);
}
END_TEST

START_TEST(test_sscanf_negative_G) {
  char buffer[100];
  char buffer_orig[100];
  float G;
  float G_orig;
  strcpy(buffer, "123.456");
  strcpy(buffer_orig, "123.456");
  ck_assert_int_eq(s21_sscanf(buffer, "%G", &G),
                   sscanf(buffer_orig, "%G", &G_orig));
  ck_assert_float_ne(G, G_orig + 1.0);
}
END_TEST

START_TEST(test_sscanf_negative_e) {
  char buffer[100];
  char buffer_orig[100];
  float e;
  float e_orig;
  strcpy(buffer, "1.234e5");
  strcpy(buffer_orig, "1.234e5");
  ck_assert_int_eq(s21_sscanf(buffer, "%e", &e),
                   sscanf(buffer_orig, "%e", &e_orig));
  ck_assert_float_ne(e, e_orig + 1.0);
}
END_TEST

START_TEST(test_sscanf_negative_E) {
  char buffer[100];
  char buffer_orig[100];
  float E;
  float E_orig;
  strcpy(buffer, "1.234E5");
  strcpy(buffer_orig, "1.234E5");
  ck_assert_int_eq(s21_sscanf(buffer, "%E", &E),
                   sscanf(buffer_orig, "%E", &E_orig));
  ck_assert_float_ne(E, E_orig + 1.0);
}
END_TEST

START_TEST(test_sscanf_negative_x) {
  char buffer[100];
  char buffer_orig[100];
  unsigned int x;
  unsigned int x_orig;
  strcpy(buffer, "1a2b3c");
  strcpy(buffer_orig, "1a2b3c");
  ck_assert_int_eq(s21_sscanf(buffer, "%x", &x),
                   sscanf(buffer_orig, "%x", &x_orig));
  ck_assert_uint_ne(x, x_orig + 1);
}
END_TEST

START_TEST(test_sscanf_negative_X) {
  char buffer[100];
  char buffer_orig[100];
  unsigned int X;
  unsigned int X_orig;
  strcpy(buffer, "1A2B3C");
  strcpy(buffer_orig, "1A2B3C");
  ck_assert_int_eq(s21_sscanf(buffer, "%X", &X),
                   sscanf(buffer_orig, "%X", &X_orig));
  ck_assert_uint_ne(X, X_orig + 1);
}
END_TEST

START_TEST(test_sscanf_negative_o) {
  char buffer[100];
  char buffer_orig[100];
  unsigned int o;
  unsigned int o_orig;
  strcpy(buffer, "12345");
  strcpy(buffer_orig, "12345");
  ck_assert_int_eq(s21_sscanf(buffer, "%o", &o),
                   sscanf(buffer_orig, "%o", &o_orig));
  ck_assert_uint_ne(o, o_orig + 1);
}
END_TEST

START_TEST(test_sscanf_negative_p) {
  char buffer[100];
  char buffer_orig[100];
  void *p;
  void *p_orig;
  strcpy(buffer, "0x7ffeeb87b6c0");
  strcpy(buffer_orig, "0x7ffeeb87b6c0");
  ck_assert_int_eq(s21_sscanf(buffer, "%p", &p),
                   sscanf(buffer_orig, "%p", &p_orig));
  ck_assert_ptr_ne(p, p_orig + 1);
}
END_TEST

START_TEST(test_sscanf_negative_width) {
  char buffer[100];
  char buffer_orig[100];
  char s[10];
  char s_orig[10];
  strcpy(buffer, "Hello World");
  strcpy(buffer_orig, "Hello World");
  ck_assert_int_eq(s21_sscanf(buffer, "%5s", s),
                   sscanf(buffer_orig, "%5s", s_orig));
  ck_assert_str_ne(s, "Hello!");
}
END_TEST

START_TEST(test_sscanf_negative_star) {
  char buffer[100];
  char buffer_orig[100];
  int d;
  int d_orig;
  strcpy(buffer, "123 456");
  strcpy(buffer_orig, "123 456");
  ck_assert_int_eq(s21_sscanf(buffer, "%*d %d", &d),
                   sscanf(buffer_orig, "%*d %d", &d_orig));
  ck_assert_int_ne(d, d_orig + 1);
}
END_TEST

START_TEST(test_sscanf_negative_length_l) {
  char buffer[100];
  char buffer_orig[100];
  long l;
  long l_orig;
  strcpy(buffer, "1234567890");
  strcpy(buffer_orig, "1234567890");
  ck_assert_int_eq(s21_sscanf(buffer, "%ld", &l),
                   sscanf(buffer_orig, "%ld", &l_orig));
  ck_assert_int_ne(l, l_orig + 1);
}
END_TEST

START_TEST(test_sscanf_negative_length_h) {
  char buffer[100];
  char buffer_orig[100];
  short h;
  short h_orig;
  strcpy(buffer, "12345");
  strcpy(buffer_orig, "12345");
  ck_assert_int_eq(s21_sscanf(buffer, "%hd", &h),
                   sscanf(buffer_orig, "%hd", &h_orig));
  ck_assert_int_ne(h, h_orig + 1);
}
END_TEST

START_TEST(test_sscanf_negative_length_L) {
  char buffer[100];
  char buffer_orig[100];
  long double L;
  long double L_orig;
  strcpy(buffer, "123.456");
  strcpy(buffer_orig, "123.456");
  ck_assert_int_eq(s21_sscanf(buffer, "%Lf", &L),
                   sscanf(buffer_orig, "%Lf", &L_orig));
  ck_assert_ldouble_ne(L, L_orig + 1.0);
}
END_TEST

START_TEST(test_sscanf_short_hex_lowercase) {
  char buffer[100];
  char buffer_orig[100];
  unsigned short int value;
  unsigned short int value_orig;
  strcpy(buffer, "1a2b");
  strcpy(buffer_orig, "1a2b");
  ck_assert_int_eq(s21_sscanf(buffer, "%hx", &value),
                   sscanf(buffer_orig, "%hx", &value_orig));
  ck_assert_int_eq(value, value_orig);
}
END_TEST

START_TEST(test_sscanf_short_hex_uppercase) {
  char buffer[100];
  char buffer_orig[100];
  unsigned short int value;
  unsigned short int value_orig;
  strcpy(buffer, "1A2B");
  strcpy(buffer_orig, "1A2B");
  ck_assert_int_eq(s21_sscanf(buffer, "%hx", &value),
                   sscanf(buffer_orig, "%hx", &value_orig));
  ck_assert_int_eq(value, value_orig);
}
END_TEST

START_TEST(test_sscanf_long_hex_lowercase) {
  char buffer[100];
  char buffer_orig[100];
  unsigned long int value;
  unsigned long int value_orig;
  strcpy(buffer, "1a2b3c4d");
  strcpy(buffer_orig, "1a2b3c4d");
  ck_assert_int_eq(s21_sscanf(buffer, "%lx", &value),
                   sscanf(buffer_orig, "%lx", &value_orig));
  ck_assert_int_eq(value, value_orig);
}
END_TEST

START_TEST(test_sscanf_long_hex_uppercase) {
  char buffer[100];
  char buffer_orig[100];
  unsigned long int value;
  unsigned long int value_orig;
  strcpy(buffer, "1A2B3C4D");
  strcpy(buffer_orig, "1A2B3C4D");
  ck_assert_int_eq(s21_sscanf(buffer, "%lx", &value),
                   sscanf(buffer_orig, "%lx", &value_orig));
  ck_assert_int_eq(value, value_orig);
}
END_TEST

START_TEST(test_sscanf_short_hex_mixed) {
  char buffer[100];
  char buffer_orig[100];
  unsigned short int value;
  unsigned short int value_orig;
  strcpy(buffer, "1a2B");
  strcpy(buffer_orig, "1a2B");
  ck_assert_int_eq(s21_sscanf(buffer, "%hx", &value),
                   sscanf(buffer_orig, "%hx", &value_orig));
  ck_assert_int_eq(value, value_orig);
}
END_TEST

START_TEST(test_sscanf_long_hex_mixed) {
  char buffer[100];
  char buffer_orig[100];
  unsigned long int value;
  unsigned long int value_orig;
  strcpy(buffer, "1a2B3c4D");
  strcpy(buffer_orig, "1a2B3c4D");
  ck_assert_int_eq(s21_sscanf(buffer, "%lx", &value),
                   sscanf(buffer_orig, "%lx", &value_orig));
  ck_assert_int_eq(value, value_orig);
}
END_TEST

START_TEST(test_sscanf_short_octal) {
  char buffer[100];
  char buffer_orig[100];
  unsigned short int value;
  unsigned short int value_orig;
  strcpy(buffer, "123");
  strcpy(buffer_orig, "123");
  ck_assert_int_eq(s21_sscanf(buffer, "%ho", &value),
                   sscanf(buffer_orig, "%ho", &value_orig));
  ck_assert_int_eq(value, value_orig);
}
END_TEST

START_TEST(test_sscanf_long_octal) {
  char buffer[100];
  char buffer_orig[100];
  unsigned long int value;
  unsigned long int value_orig;
  strcpy(buffer, "1234567");
  strcpy(buffer_orig, "1234567");
  ck_assert_int_eq(s21_sscanf(buffer, "%lo", &value),
                   sscanf(buffer_orig, "%lo", &value_orig));
  ck_assert_int_eq(value, value_orig);
}
END_TEST

START_TEST(test_sscanf_short_octal_with_leading_zero) {
  char buffer[100];
  char buffer_orig[100];
  unsigned short int value;
  unsigned short int value_orig;
  strcpy(buffer, "0123");
  strcpy(buffer_orig, "0123");
  ck_assert_int_eq(s21_sscanf(buffer, "%ho", &value),
                   sscanf(buffer_orig, "%ho", &value_orig));
  ck_assert_int_eq(value, value_orig);
}
END_TEST

START_TEST(test_sscanf_long_octal_with_leading_zero) {
  char buffer[100];
  char buffer_orig[100];
  unsigned long int value;
  unsigned long int value_orig;
  strcpy(buffer, "01234567");
  strcpy(buffer_orig, "01234567");
  ck_assert_int_eq(s21_sscanf(buffer, "%lo", &value),
                   sscanf(buffer_orig, "%lo", &value_orig));
  ck_assert_int_eq(value, value_orig);
}
END_TEST

START_TEST(test_sscanf_short_octal_mixed) {
  char buffer[100];
  char buffer_orig[100];
  unsigned short int value;
  unsigned short int value_orig;
  strcpy(buffer, "01234567");
  strcpy(buffer_orig, "01234567");
  ck_assert_int_eq(s21_sscanf(buffer, "%ho", &value),
                   sscanf(buffer_orig, "%ho", &value_orig));
  ck_assert_int_eq(value, value_orig);
}
END_TEST

START_TEST(test_sscanf_long_octal_mixed) {
  char buffer[100];
  char buffer_orig[100];
  unsigned long int value;
  unsigned long int value_orig;
  strcpy(buffer, "0123456701234567");
  strcpy(buffer_orig, "0123456701234567");
  ck_assert_int_eq(s21_sscanf(buffer, "%lo", &value),
                   sscanf(buffer_orig, "%lo", &value_orig));
  ck_assert_int_eq(value, value_orig);
}
END_TEST
START_TEST(test_sscanf_float_exponent_positive) {
  char buffer[100];
  char buffer_orig[100];
  float value;
  float value_orig;
  strcpy(buffer, "1.23e4");
  strcpy(buffer_orig, "1.23e4");
  ck_assert_int_eq(s21_sscanf(buffer, "%f", &value),
                   sscanf(buffer_orig, "%f", &value_orig));
  ck_assert_float_eq(value, value_orig);
}
END_TEST

START_TEST(test_sscanf_float_exponent_negative) {
  char buffer[100];
  char buffer_orig[100];
  float value;
  float value_orig;
  strcpy(buffer, "1.23e-4");
  strcpy(buffer_orig, "1.23e-4");
  ck_assert_int_eq(s21_sscanf(buffer, "%f", &value),
                   sscanf(buffer_orig, "%f", &value_orig));
  ck_assert_float_eq(value, value_orig);
}
END_TEST

START_TEST(test_sscanf_float_exponent_uppercase) {
  char buffer[100];
  char buffer_orig[100];
  float value;
  float value_orig;
  strcpy(buffer, "1.23E4");
  strcpy(buffer_orig, "1.23E4");
  ck_assert_int_eq(s21_sscanf(buffer, "%f", &value),
                   sscanf(buffer_orig, "%f", &value_orig));
  ck_assert_float_eq(value, value_orig);
}
END_TEST

START_TEST(test_sscanf_float_exponent_uppercase_negative) {
  char buffer[100];
  char buffer_orig[100];
  float value;
  float value_orig;
  strcpy(buffer, "1.23E-4");
  strcpy(buffer_orig, "1.23E-4");
  ck_assert_int_eq(s21_sscanf(buffer, "%f", &value),
                   sscanf(buffer_orig, "%f", &value_orig));
  ck_assert_float_eq(value, value_orig);
}
END_TEST

START_TEST(test_sscanf_float_exponent_with_sign) {
  char buffer[100];
  char buffer_orig[100];
  float value;
  float value_orig;
  strcpy(buffer, "1.23e+4");
  strcpy(buffer_orig, "1.23e+4");
  ck_assert_int_eq(s21_sscanf(buffer, "%f", &value),
                   sscanf(buffer_orig, "%f", &value_orig));
  ck_assert_float_eq(value, value_orig);
}
END_TEST

START_TEST(test_sscanf_float_exponent_with_negative_sign) {
  char buffer[100];
  char buffer_orig[100];
  float value;
  float value_orig;
  strcpy(buffer, "1.23e-4");
  strcpy(buffer_orig, "1.23e-4");
  ck_assert_int_eq(s21_sscanf(buffer, "%f", &value),
                   sscanf(buffer_orig, "%f", &value_orig));
  ck_assert_float_eq(value, value_orig);
}
END_TEST

START_TEST(test_sscanf_float_exponent_with_uppercase_sign) {
  char buffer[100];
  char buffer_orig[100];
  float value;
  float value_orig;
  strcpy(buffer, "1.23E+4");
  strcpy(buffer_orig, "1.23E+4");
  ck_assert_int_eq(s21_sscanf(buffer, "%f", &value),
                   sscanf(buffer_orig, "%f", &value_orig));
  ck_assert_float_eq(value, value_orig);
}
END_TEST

START_TEST(test_sscanf_float_exponent_with_uppercase_negative_sign) {
  char buffer[100];
  char buffer_orig[100];
  float value;
  float value_orig;
  strcpy(buffer, "1.23E-4");
  strcpy(buffer_orig, "1.23E-4");
  ck_assert_int_eq(s21_sscanf(buffer, "%f", &value),
                   sscanf(buffer_orig, "%f", &value_orig));
  ck_assert_float_eq(value, value_orig);
}
END_TEST

START_TEST(test_sscanf_wide_string) {
  char buffer[100];
  char buffer_orig[100];
  char wide_buffer[100];
  char wide_buffer_orig[100];
  strcpy(buffer, "Hello World");
  strcpy(buffer_orig, "Hello World");
  ck_assert_int_eq(s21_sscanf(buffer, "%s", wide_buffer),
                   sscanf(buffer_orig, "%s", wide_buffer_orig));
  ck_assert_str_eq(wide_buffer, wide_buffer_orig);
}
END_TEST

START_TEST(test_sscanf_wide_string_with_width) {
  char buffer[100];
  char buffer_orig[100];
  char wide_buffer[100];
  char wide_buffer_orig[100];
  strcpy(buffer, "Hello World");
  strcpy(buffer_orig, "Hello World");
  ck_assert_int_eq(s21_sscanf(buffer, "%5s", wide_buffer),
                   sscanf(buffer_orig, "%5s", wide_buffer_orig));
  ck_assert_str_eq(wide_buffer, wide_buffer_orig);
}
END_TEST

START_TEST(test_sscanf_wide_char) {
  char buffer[100];
  char buffer_orig[100];
  char wide_char;
  char wide_char_orig;
  strcpy(buffer, "A");
  strcpy(buffer_orig, "A");
  ck_assert_int_eq(s21_sscanf(buffer, "%c", &wide_char),
                   sscanf(buffer_orig, "%c", &wide_char_orig));
  ck_assert_int_eq(wide_char, wide_char_orig);
}
END_TEST

START_TEST(test_sscanf_skip_whitespace) {
  char buffer[100];
  char buffer_orig[100];
  int value;
  int value_orig;
  strcpy(buffer, "  123");
  strcpy(buffer_orig, "  123");
  ck_assert_int_eq(s21_sscanf(buffer, "%d", &value),
                   sscanf(buffer_orig, "%d", &value_orig));
  ck_assert_int_eq(value, value_orig);
}
END_TEST

START_TEST(test_sscanf_wide_string_with_spaces) {
  char buffer[100];
  char buffer_orig[100];
  char wide_buffer[100];
  char wide_buffer_orig[100];
  strcpy(buffer, "  Hello World  ");
  strcpy(buffer_orig, "  Hello World  ");
  ck_assert_int_eq(s21_sscanf(buffer, "%s", wide_buffer),
                   sscanf(buffer_orig, "%s", wide_buffer_orig));
  ck_assert_str_eq(wide_buffer, wide_buffer_orig);
}
END_TEST

START_TEST(test_sscanf_wide_char_with_spaces) {
  char buffer[100];
  char buffer_orig[100];
  char wide_char;
  char wide_char_orig;
  strcpy(buffer, "  A  ");
  strcpy(buffer_orig, "  A  ");
  ck_assert_int_eq(s21_sscanf(buffer, "%c", &wide_char),
                   sscanf(buffer_orig, "%c", &wide_char_orig));
  ck_assert_int_eq(wide_char, wide_char_orig);
}
END_TEST

START_TEST(test_skip_whitespace) {
  char buffer[100];
  char buffer_orig[100];
  strcpy(buffer, "   Hello World  ");
  strcpy(buffer_orig, "   Hello World  ");
  ck_assert_int_eq(s21_sscanf(buffer, "%s", buffer),
                   sscanf(buffer_orig, "%s", buffer_orig));
  ck_assert_str_eq(buffer, buffer_orig);
}
END_TEST

START_TEST(test_read_wide_string) {
  char buffer[100];
  char buffer_orig[100];
  char wide_buffer[100];
  char wide_buffer_orig[100];
  strcpy(buffer, "  Hello World  ");
  strcpy(buffer_orig, "  Hello World  ");
  ck_assert_int_eq(s21_sscanf(buffer, "%s", wide_buffer),
                   sscanf(buffer_orig, "%s", wide_buffer_orig));
  ck_assert_str_eq(wide_buffer, wide_buffer_orig);
}
END_TEST

START_TEST(test_read_wide_char) {
  char buffer[100];
  char buffer_orig[100];
  char wide_char;
  char wide_char_orig;
  strcpy(buffer, "H");
  strcpy(buffer_orig, "H");
  ck_assert_int_eq(s21_sscanf(buffer, "%c", &wide_char),
                   sscanf(buffer_orig, "%c", &wide_char_orig));
  ck_assert_int_eq(wide_char, wide_char_orig);
}
END_TEST

START_TEST(test_read_float) {
  char buffer[100];
  char buffer_orig[100];
  float value;
  float value_orig;
  strcpy(buffer, "123.456e-2");
  strcpy(buffer_orig, "123.456e-2");
  ck_assert_int_eq(s21_sscanf(buffer, "%f", &value),
                   sscanf(buffer_orig, "%f", &value_orig));
  ck_assert_float_eq(value, value_orig);
}
END_TEST

START_TEST(test_read_short_int) {
  char buffer[100];
  char buffer_orig[100];
  short int value;
  short int value_orig;
  strcpy(buffer, "-123");
  strcpy(buffer_orig, "-123");
  ck_assert_int_eq(s21_sscanf(buffer, "%hd", &value),
                   sscanf(buffer_orig, "%hd", &value_orig));
  ck_assert_int_eq(value, value_orig);
}
END_TEST

START_TEST(test_read_long_int) {
  char buffer[100];
  char buffer_orig[100];
  long int value;
  long int value_orig;
  strcpy(buffer, "-1234567890");
  strcpy(buffer_orig, "-1234567890");
  ck_assert_int_eq(s21_sscanf(buffer, "%ld", &value),
                   sscanf(buffer_orig, "%ld", &value_orig));
  ck_assert_int_eq(value, value_orig);
}
END_TEST

START_TEST(test_read_octal) {
  char buffer[100];
  char buffer_orig[100];
  unsigned int value;
  unsigned int value_orig;
  strcpy(buffer, "123");
  strcpy(buffer_orig, "123");
  ck_assert_int_eq(s21_sscanf(buffer, "%o", &value),
                   sscanf(buffer_orig, "%o", &value_orig));
  ck_assert_int_eq(value, value_orig);
}
END_TEST

START_TEST(test_read_hex) {
  char buffer[100];
  char buffer_orig[100];
  unsigned int value;
  unsigned int value_orig;
  strcpy(buffer, "1A2B3C");
  strcpy(buffer_orig, "1A2B3C");
  ck_assert_int_eq(s21_sscanf(buffer, "%x", &value),
                   sscanf(buffer_orig, "%x", &value_orig));
  ck_assert_int_eq(value, value_orig);
}
END_TEST

START_TEST(test_read_pointer) {
  char buffer[100];
  char buffer_orig[100];
  void *value;
  void *value_orig;
  strcpy(buffer, "0x12345678");
  strcpy(buffer_orig, "0x12345678");
  ck_assert_int_eq(s21_sscanf(buffer, "%p", &value),
                   sscanf(buffer_orig, "%p", &value_orig));
  ck_assert_ptr_eq(value, value_orig);
}
END_TEST

START_TEST(test_read_long_double) {
  char buffer[100];
  char buffer_orig[100];
  long double value;
  long double value_orig;
  strcpy(buffer, "123.456e-2");
  strcpy(buffer_orig, "123.456e-2");
  ck_assert_int_eq(s21_sscanf(buffer, "%Lf", &value),
                   sscanf(buffer_orig, "%Lf", &value_orig));
  // ck_assert_ldouble_eq(value, value_orig);
}
END_TEST

Suite *test_sscanf() {
  Suite *s = suite_create("s21_sscanf");
  TCase *tc = tcase_create("s21_sscanf");

  tcase_add_test(tc, test_sscanf_c);
  tcase_add_test(tc, test_sscanf_d);
  tcase_add_test(tc, test_sscanf_f);
  tcase_add_test(tc, test_sscanf_s);
  tcase_add_test(tc, test_sscanf_u);
  tcase_add_test(tc, test_sscanf_percent);
  tcase_add_test(tc, test_sscanf_g);
  tcase_add_test(tc, test_sscanf_G);
  tcase_add_test(tc, test_sscanf_e);
  tcase_add_test(tc, test_sscanf_E);
  tcase_add_test(tc, test_sscanf_x);
  tcase_add_test(tc, test_sscanf_X);
  tcase_add_test(tc, test_sscanf_o);
  tcase_add_test(tc, test_sscanf_p);
  tcase_add_test(tc, test_sscanf_width);
  tcase_add_test(tc, test_sscanf_star);
  tcase_add_test(tc, test_sscanf_length_l);
  tcase_add_test(tc, test_sscanf_length_h);
  tcase_add_test(tc, test_sscanf_length_L);

  tcase_add_test(tc, test_sscanf_short_hex_lowercase);
  tcase_add_test(tc, test_sscanf_short_hex_uppercase);
  tcase_add_test(tc, test_sscanf_long_hex_lowercase);
  tcase_add_test(tc, test_sscanf_long_hex_uppercase);
  tcase_add_test(tc, test_sscanf_short_hex_mixed);
  tcase_add_test(tc, test_sscanf_long_hex_mixed);
  tcase_add_test(tc, test_sscanf_short_octal);
  tcase_add_test(tc, test_sscanf_long_octal);
  tcase_add_test(tc, test_sscanf_short_octal_with_leading_zero);
  tcase_add_test(tc, test_sscanf_long_octal_with_leading_zero);
  tcase_add_test(tc, test_sscanf_short_octal_mixed);
  tcase_add_test(tc, test_sscanf_long_octal_mixed);
  tcase_add_test(tc, test_sscanf_float_exponent_positive);
  tcase_add_test(tc, test_sscanf_float_exponent_negative);
  tcase_add_test(tc, test_sscanf_float_exponent_uppercase);
  tcase_add_test(tc, test_sscanf_float_exponent_uppercase_negative);
  tcase_add_test(tc, test_sscanf_float_exponent_with_sign);
  tcase_add_test(tc, test_sscanf_float_exponent_with_negative_sign);
  tcase_add_test(tc, test_sscanf_float_exponent_with_uppercase_sign);
  tcase_add_test(tc, test_sscanf_float_exponent_with_uppercase_negative_sign);
  tcase_add_test(tc, test_sscanf_wide_string);
  tcase_add_test(tc, test_sscanf_wide_string_with_width);
  tcase_add_test(tc, test_sscanf_wide_char);
  tcase_add_test(tc, test_sscanf_skip_whitespace);
  tcase_add_test(tc, test_sscanf_wide_string_with_spaces);
  tcase_add_test(tc, test_sscanf_wide_char_with_spaces);

  tcase_add_test(tc, test_skip_whitespace);
  tcase_add_test(tc, test_read_wide_string);
  tcase_add_test(tc, test_read_wide_char);
  tcase_add_test(tc, test_read_float);
  tcase_add_test(tc, test_read_short_int);
  tcase_add_test(tc, test_read_long_int);
  tcase_add_test(tc, test_read_octal);
  tcase_add_test(tc, test_read_hex);
  tcase_add_test(tc, test_read_pointer);
  tcase_add_test(tc, test_read_long_double);

  tcase_add_test(tc, test_sscanf_negative_c);
  tcase_add_test(tc, test_sscanf_negative_d);
  tcase_add_test(tc, test_sscanf_negative_f);
  tcase_add_test(tc, test_sscanf_negative_s);
  tcase_add_test(tc, test_sscanf_negative_u);
  tcase_add_test(tc, test_sscanf_negative_percent);
  tcase_add_test(tc, test_sscanf_negative_g);
  tcase_add_test(tc, test_sscanf_negative_G);
  tcase_add_test(tc, test_sscanf_negative_e);
  tcase_add_test(tc, test_sscanf_negative_E);
  tcase_add_test(tc, test_sscanf_negative_x);
  tcase_add_test(tc, test_sscanf_negative_X);
  tcase_add_test(tc, test_sscanf_negative_o);
  tcase_add_test(tc, test_sscanf_negative_p);
  tcase_add_test(tc, test_sscanf_negative_width);
  tcase_add_test(tc, test_sscanf_negative_star);
  tcase_add_test(tc, test_sscanf_negative_length_l);
  tcase_add_test(tc, test_sscanf_negative_length_h);
  tcase_add_test(tc, test_sscanf_negative_length_L);

  suite_add_tcase(s, tc);
  return s;
}
