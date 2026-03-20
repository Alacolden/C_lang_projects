#include <ctype.h>
#include <math.h>

#include "s21_string.h"

#define MAX_LEN_TEMP 128
#define COUNT_FLAGS 4
#define UTF8_BUFFER 4
#define TEMP_INT 32

typedef struct Modifiers {
  char flags[COUNT_FLAGS];
  int width;
  int precision;
  char length;
} Modifiers;

void init_modifiers(Modifiers* modifiers);
const char* char_to_int(const char* ptr, int* result);
const char* parse_modifiers(const char* ptr, Modifiers* modifiers);
char* specifiers(char spec, va_list args, char* dest, Modifiers modifiers);
char* add_width(char* dest, char temp[MAX_LEN_TEMP], Modifiers modifiers,
                int len_temp);
int has_flag(Modifiers m, char flag);
int wchar_to_utf8(wchar_t wch, char* out);
char* spec_d(char* dest, va_list args, Modifiers m);
char* spec_u(char* dest, va_list args, Modifiers m);
char* spec_s(char* dest, va_list args, Modifiers m);
void prec_for_str(char buffer[MAX_LEN_TEMP], char* str, int precision);
int int_to_string(long num, char* buffer, int precision);
int uint_to_string(unsigned long num, char* buffer, int precision);
int double_to_string(double double_num, char* buffer, int precision);

int s21_sprintf(char* str, const char* format, ...) {
  va_list args;
  va_start(args, format);

  char* dest = str;
  const char* ptr = format;

  while (*ptr) {
    if (*ptr == '%') {
      ptr++;

      Modifiers modifiers;
      init_modifiers(&modifiers);
      ptr = parse_modifiers(ptr, &modifiers);

      char spec = *ptr;
      dest = specifiers(spec, args, dest, modifiers);
    } else {
      *dest++ = *ptr;
    }
    ptr++;
  }

  *dest = '\0';
  va_end(args);
  return dest - str;
}

void init_modifiers(Modifiers* modifiers) {
  modifiers->flags[0] = '\0';
  modifiers->width = 0;
  modifiers->precision = -1;
  modifiers->length = '\0';
}

const char* parse_modifiers(const char* ptr, Modifiers* modifiers) {
  int flag_index = 0;
  while (*ptr == '+' || *ptr == '-' || *ptr == ' ') {
    if (flag_index < COUNT_FLAGS) {
      modifiers->flags[flag_index++] = *ptr;
    }
    ptr++;
  }
  modifiers->flags[flag_index] = '\0';

  if (isdigit(*ptr)) {
    ptr = char_to_int(ptr, &modifiers->width);
  }

  if (*ptr == '.') {
    ptr++;
    ptr = char_to_int(ptr, &modifiers->precision);
  }

  if (*ptr == 'h') {
    modifiers->length = 'h';
    ptr++;
  } else if (*ptr == 'l') {
    modifiers->length = 'l';
    ptr++;
  }
  return ptr;
}

const char* char_to_int(const char* ptr, int* result) {
  *result = 0;
  while (isdigit(*ptr)) {
    *result = (*result) * 10 + (*ptr - '0');
    ptr++;
  }
  return ptr;
}

char* specifiers(char spec, va_list args, char* dest, Modifiers modifiers) {
  if (spec == 'c') {
    char temp_char[MAX_LEN_TEMP];
    int len = 0;
    if (modifiers.length == 'l') {
      wchar_t wch = va_arg(args, wchar_t);
      char utf8[UTF8_BUFFER];
      len = wchar_to_utf8(wch, utf8);
      s21_memcpy(temp_char, utf8, len);
    } else if (modifiers.length != 'h') {
      char ch = (char)va_arg(args, int);
      temp_char[0] = ch;
      len = 1;
    }
    temp_char[len] = '\0';
    dest = add_width(dest, temp_char, modifiers, len);
  } else if (spec == 'd') {
    dest = spec_d(dest, args, modifiers);
  } else if (spec == 'f') {
    double d_num = va_arg(args, double);
    char temp_double[MAX_LEN_TEMP];
    int len = double_to_string(d_num, temp_double, modifiers.precision);
    dest = add_width(dest, temp_double, modifiers, len);
  } else if (spec == 's') {
    dest = spec_s(dest, args, modifiers);
  } else if (spec == 'u') {
    dest = spec_u(dest, args, modifiers);
  } else if (spec == '%') {
    *dest++ = '%';
  }
  return dest;
}

int wchar_to_utf8(wchar_t wch, char* out) {
  int len = 0;
  if (wch < 0x80) {
    out[0] = wch;
    len = 1;
  } else if (wch < 0x800) {
    out[0] = 0xC0 | (wch >> 6);
    out[1] = 0x80 | (wch & 0x3F);
    len = 2;
  } else if (wch < 0x10000) {
    out[0] = 0xE0 | (wch >> 12);
    out[1] = 0x80 | ((wch >> 6) & 0x3F);
    out[2] = 0x80 | (wch & 0x3F);
    len = 3;
  } else {
    out[0] = 0xF0 | (wch >> 18);
    out[1] = 0x80 | ((wch >> 12) & 0x3F);
    out[2] = 0x80 | ((wch >> 6) & 0x3F);
    out[3] = 0x80 | (wch & 0x3F);
    len = 4;
  }
  return len;
}

char* spec_d(char* dest, va_list args, Modifiers m) {
  long l_val = 0;
  int i_val = 0;
  char temp_int[MAX_LEN_TEMP];
  int len;

  if (m.length == 'h') {
    i_val = (short)va_arg(args, int);
    len = int_to_string((long)i_val, temp_int, m.precision);
  } else if (m.length == 'l') {
    l_val = (long)va_arg(args, long);
    len = int_to_string(l_val, temp_int, m.precision);
  } else {
    i_val = (int)va_arg(args, int);
    len = int_to_string((long)i_val, temp_int, m.precision);
  }

  return add_width(dest, temp_int, m, len);
}

char* spec_u(char* dest, va_list args, Modifiers m) {
  unsigned long ul_val = 0;
  unsigned int ui_val = 0;
  char temp_uint[MAX_LEN_TEMP];
  int len;

  if (m.length == 'h') {
    ui_val = (unsigned short)va_arg(args, unsigned int);
    len = uint_to_string((unsigned long)ui_val, temp_uint, m.precision);
  } else if (m.length == 'l') {
    ul_val = (unsigned long)va_arg(args, unsigned long);
    len = uint_to_string(ul_val, temp_uint, m.precision);
  } else {
    ui_val = (unsigned int)va_arg(args, unsigned int);
    len = uint_to_string((unsigned long)ui_val, temp_uint, m.precision);
  }

  return add_width(dest, temp_uint, m, len);
}

char* spec_s(char* dest, va_list args, Modifiers m) {
  char temp_str[MAX_LEN_TEMP];
  if (m.length == 'l') {
    wchar_t* wstr = va_arg(args, wchar_t*);
    char temp_wstr[MAX_LEN_TEMP];
    char* wptr = temp_wstr;

    while (*wstr) {
      char utf8[UTF8_BUFFER];
      int len = wchar_to_utf8(*wstr++, utf8);

      if (m.precision >= 0) {
        if ((wptr - temp_wstr) + len > m.precision) break;
      }

      s21_memcpy(wptr, utf8, len);
      wptr += len;
    }
    *wptr = '\0';

    prec_for_str(temp_str, temp_wstr, -1);
  } else {
    char* str = va_arg(args, char*);
    prec_for_str(temp_str, str, m.precision);
  }
  return add_width(dest, temp_str, m, s21_strlen(temp_str));
}

void prec_for_str(char buffer[MAX_LEN_TEMP], char* str, int precision) {
  int i = 0;
  if (precision == -1) {
    while (*str) {
      buffer[i++] = *str++;
    }
  } else {
    while (*str && precision > 0) {
      buffer[i++] = *str++;
      precision--;
    }
  }
  buffer[i] = '\0';
}

char* add_width(char* dest, char temp[MAX_LEN_TEMP], Modifiers modifiers,
                int len_temp) {
  int width = modifiers.width;
  int add_plus = has_flag(modifiers, '+') && isdigit(temp[0]);

  if (has_flag(modifiers, ' ') && !has_flag(modifiers, '+')) {
    *dest++ = ' ';
    width--;
  }

  if (has_flag(modifiers, '-')) {
    if (add_plus) {
      *dest++ = '+';
      width--;
    }

    for (int i = 0; i < len_temp; i++) {
      *dest++ = temp[i];
      width--;
    }

    while (width > 0) {
      *dest++ = ' ';
      width--;
    }
  } else {
    while (width - add_plus > len_temp) {
      *dest++ = ' ';
      width--;
    }

    if (add_plus) *dest++ = '+';

    for (int i = 0; i < len_temp; i++) {
      *dest++ = temp[i];
    }
  }
  return dest;
}

int has_flag(Modifiers m, char flag) {
  int equality = 0;
  for (int i = 0; m.flags[i] != '\0'; i++) {
    if (m.flags[i] == flag) {
      equality = 1;
      break;
    }
  }
  return equality;
}

int int_to_string(long num, char* buffer, int precision) {
  char* start = buffer;
  unsigned long abs_num = num;

  if (num < 0) {
    *buffer++ = '-';
    abs_num = -num;
  }

  int len = uint_to_string(abs_num, buffer, precision);
  return (buffer - start) + len;
}

int uint_to_string(unsigned long num, char* buffer, int precision) {
  char temp[TEMP_INT];
  int i = 0;

  if (num == 0) {
    if (precision == 0) {
      buffer[0] = '\0';
      return 0;
    } else {
      temp[i++] = '0';
    }
  }

  while (num > 0) {
    temp[i++] = (num % 10) + '0';
    num /= 10;
  }

  int j = 0;
  while (j < precision - i) {
    buffer[j++] = '0';
  }

  while (i > 0) {
    buffer[j++] = temp[--i];
  }

  buffer[j] = '\0';
  return j;
}

int double_to_string(double double_num, char* buffer, int precision) {
  if (precision == -1) {
    precision = 6;
  }
  char* start = buffer;
  int len_double = 0;

  int negative = 0;
  if (double_num < 0) {
    negative = 1;
    double_num = -double_num;
  }

  double pow10 = pow(10, precision);
  long long scaled = llround(double_num * pow10);

  long long int_part = scaled / (long long)pow10;
  long long frac_part = scaled % (long long)pow10;

  if (negative) *buffer++ = '-';

  char temp_int[TEMP_INT];
  int len_int = uint_to_string((unsigned long)int_part, temp_int, 1);
  for (int i = 0; i < len_int; i++) {
    *buffer++ = temp_int[i];
  }

  if (precision == 0) {
    *buffer = '\0';
    len_double = buffer - start;
  } else {
    *buffer++ = '.';

    char frac_buf[TEMP_INT];
    for (int i = precision - 1; i >= 0; i--) {
      frac_buf[i] = (frac_part % 10) + '0';
      frac_part /= 10;
    }

    for (int i = 0; i < precision; i++) {
      *buffer++ = frac_buf[i];
    }
    *buffer = '\0';
    len_double = buffer - start;
  }

  return len_double;
}