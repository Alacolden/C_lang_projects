#include "s21_test.h"

START_TEST(s21_from_decimal_to_float_01) {
  s21_decimal src_decimal = {
      .bits = {0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  float dst_float;
  float etalon_float = 0.f;
  int s21_error = s21_from_decimal_to_float(src_decimal, &dst_float);
  ck_assert_float_eq(etalon_float, dst_float);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_float_02) {
  s21_decimal src_decimal = {
      .bits = {0x00000000, 0x00000000, 0x00000000, 0x80000000}};
  float dst_float;
  float etalon_float = -0.f;
  int s21_error = s21_from_decimal_to_float(src_decimal, &dst_float);
  ck_assert_float_eq(etalon_float, dst_float);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_float_03) {
  s21_decimal src_decimal = {
      .bits = {0x00000C8E, 0x00000000, 0x00000000, 0x80010000}};
  float dst_float;
  float etalon_float = -321.4f;
  int s21_error = s21_from_decimal_to_float(src_decimal, &dst_float);
  ck_assert_float_eq(etalon_float, dst_float);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_float_04) {
  s21_decimal src_decimal = {
      .bits = {0x3FC56AB0, 0x00000000, 0x00000000, 0x801C0000}};
  float dst_float;
  float etalon_float = -0.0000000000000000001069902512f;
  int s21_error = s21_from_decimal_to_float(src_decimal, &dst_float);
  ck_assert_float_eq(etalon_float, dst_float);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_float_05) {
  s21_decimal src_decimal = {
      .bits = {0x00000001, 0x00000000, 0x00000000, 0x001C0000}};
  float dst_float;
  float etalon_float = 0.0000000000000000000000000001f;
  int s21_error = s21_from_decimal_to_float(src_decimal, &dst_float);
  ck_assert_float_eq(etalon_float, dst_float);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_float_06) {
  s21_decimal src_decimal = {
      .bits = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x001C0000}};
  float dst_float;
  float etalon_float = 7.9228162514264337593543950335f;
  int s21_error = s21_from_decimal_to_float(src_decimal, &dst_float);
  ck_assert_float_eq(etalon_float, dst_float);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_float_07) {
  s21_decimal src_decimal = {
      .bits = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  float dst_float;
  float etalon_float = 79228162514264337593543950335.f;
  int s21_error = s21_from_decimal_to_float(src_decimal, &dst_float);
  ck_assert_float_eq(etalon_float, dst_float);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_float_08) {
  s21_decimal src_decimal = {
      .bits = {0x0004F3AC, 0x00000000, 0x00000000, 0x00060000}};
  float dst_float;
  float etalon_float = 0.324524f;
  int s21_error = s21_from_decimal_to_float(src_decimal, &dst_float);
  ck_assert_float_eq(etalon_float, dst_float);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_float_09) {
  s21_decimal src_decimal = {
      .bits = {0x0008FD43, 0x00000000, 0x00000000, 0x000A0000}};
  float dst_float;
  float etalon_float = 0.0000589123f;
  int s21_error = s21_from_decimal_to_float(src_decimal, &dst_float);
  ck_assert_float_eq(etalon_float, dst_float);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_float_10) {
  s21_decimal src_decimal = {
      .bits = {0x0382EE63, 0x00000000, 0x00000000, 0x00050000}};
  float dst_float;
  float etalon_float = 589.12355;
  int s21_error = s21_from_decimal_to_float(src_decimal, &dst_float);
  ck_assert_float_eq(etalon_float, dst_float);
  ck_assert_int_eq(0, s21_error);
}
END_TEST
START_TEST(s21_from_decimal_to_int_01) {
  s21_decimal src_decimal = {.bits = {0x00000000, 0, 0, 0x00000000}};
  int dst_int;
  int etalon_int = 0;
  int s21_error = s21_from_decimal_to_int(src_decimal, &dst_int);
  ck_assert_int_eq(etalon_int, dst_int);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_int_02) {
  s21_decimal src_decimal = {.bits = {0x00000000, 0, 0, 0x80000000}};
  int dst_int;
  int etalon_int = 0;
  int s21_error = s21_from_decimal_to_int(src_decimal, &dst_int);
  ck_assert_int_eq(etalon_int, dst_int);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_int_03) {
  s21_decimal src_decimal = {.bits = {0x00000C8E, 0, 0, 0x00010000}};
  int dst_int;
  int etalon_int = 321;
  int s21_error = s21_from_decimal_to_int(src_decimal, &dst_int);
  ck_assert_int_eq(etalon_int, dst_int);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_int_04) {
  s21_decimal src_decimal = {.bits = {0x00000C8E, 0, 0, 0x80010000}};
  int dst_int;
  int etalon_int = -321;
  int s21_error = s21_from_decimal_to_int(src_decimal, &dst_int);
  ck_assert_int_eq(etalon_int, dst_int);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_int_05) {
  s21_decimal src_decimal = {.bits = {0x00000141, 0, 0, 0x00030000}};
  int dst_int;
  int etalon_int = 0;
  int s21_error = s21_from_decimal_to_int(src_decimal, &dst_int);
  ck_assert_int_eq(etalon_int, dst_int);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_int_06) {
  s21_decimal src_decimal = {.bits = {0x00000141, 0, 0, 0x80030000}};
  int dst_int;
  int etalon_int = 0;
  int s21_error = s21_from_decimal_to_int(src_decimal, &dst_int);
  ck_assert_int_eq(etalon_int, dst_int);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_int_07) {
  s21_decimal src_decimal = {.bits = {0x00007DA7, 0, 0, 0x00020000}};
  int dst_int;
  int etalon_int = 321;
  int s21_error = s21_from_decimal_to_int(src_decimal, &dst_int);
  ck_assert_int_eq(etalon_int, dst_int);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_int_08) {
  s21_decimal src_decimal = {.bits = {0x00007DA7, 0, 0, 0x80020000}};
  int dst_int;
  int etalon_int = -321;
  int s21_error = s21_from_decimal_to_int(src_decimal, &dst_int);
  ck_assert_int_eq(etalon_int, dst_int);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_int_09) {
  s21_decimal src_decimal = {.bits = {0x00000141, 0, 0, 0x00000000}};
  int dst_int;
  int etalon_int = 321;
  int s21_error = s21_from_decimal_to_int(src_decimal, &dst_int);
  ck_assert_int_eq(etalon_int, dst_int);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_int_10) {
  s21_decimal src_decimal = {.bits = {0x00000141, 0, 0, 0x80000000}};
  int dst_int;
  int etalon_int = -321;
  int s21_error = s21_from_decimal_to_int(src_decimal, &dst_int);
  ck_assert_int_eq(etalon_int, dst_int);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_int_11) {
  s21_decimal src_decimal = {.bits = {0x01E9FED9, 0, 0, 0x00050000}};
  int dst_int;
  int etalon_int = 321;
  int s21_error = s21_from_decimal_to_int(src_decimal, &dst_int);
  ck_assert_int_eq(etalon_int, dst_int);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_int_12) {
  s21_decimal src_decimal = {.bits = {0x01E9FED9, 0, 0, 0x80050000}};
  int dst_int;
  int etalon_int = -321;
  int s21_error = s21_from_decimal_to_int(src_decimal, &dst_int);
  ck_assert_int_eq(etalon_int, dst_int);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_int_13) {
  s21_decimal src_decimal = {.bits = {INT_MAX, 0, 0, 0x00000000}};
  int dst_int;
  int etalon_int = INT_MAX;
  int s21_error = s21_from_decimal_to_int(src_decimal, &dst_int);
  ck_assert_int_eq(etalon_int, dst_int);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_int_15) {
  s21_decimal src_decimal = {.bits = {0x00000001, 0, 0, 0x001C0000}};
  int dst_int;
  int etalon_int = 0;
  int s21_error = s21_from_decimal_to_int(src_decimal, &dst_int);
  ck_assert_int_eq(etalon_int, dst_int);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_int_16) {
  s21_decimal src_decimal = {.bits = {0x00000001, 0, 0, 0x801C0000}};
  int dst_int;
  int etalon_int = 0;
  int s21_error = s21_from_decimal_to_int(src_decimal, &dst_int);
  ck_assert_int_eq(etalon_int, dst_int);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_int_17) {
  s21_decimal src_decimal = {
      .bits = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x001C0000}};
  int dst_int;
  int etalon_int = 7;
  int s21_error = s21_from_decimal_to_int(src_decimal, &dst_int);
  ck_assert_int_eq(etalon_int, dst_int);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_int_18) {
  s21_decimal src_decimal = {
      .bits = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  int dst_int;
  int etalon_int = -7;
  int s21_error = s21_from_decimal_to_int(src_decimal, &dst_int);
  ck_assert_int_eq(etalon_int, dst_int);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_int_19) {
  s21_decimal src_decimal = {.bits = {0xFFFFFFFF, 0, 0, 0x00000000}};
  int dst_int = 0;
  int etalon_int = 0;
  int s21_error = s21_from_decimal_to_int(src_decimal, &dst_int);
  ck_assert_int_eq(etalon_int, dst_int);
  ck_assert_int_eq(1, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_int_20) {
  s21_decimal src_decimal = {.bits = {0xFFFFFFFF, 0, 0, 0x80000000}};
  int dst_int = 0;
  int etalon_int = 0;
  int s21_error = s21_from_decimal_to_int(src_decimal, &dst_int);
  ck_assert_int_eq(etalon_int, dst_int);
  ck_assert_int_eq(1, s21_error);
}
END_TEST
START_TEST(s21_from_float_to_decimal_001) {
  float src_float = 1.0f / 0.0f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {.bits = {0, 0, 0, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(1, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_002) {
  float src_float = -1.0f / 0.0f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {.bits = {0, 0, 0, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(1, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_003) {
  float src_float = 0.0f / 0.0f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {.bits = {0, 0, 0, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(1, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_007) {
  float src_float = 73.329959999f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {.bits = {0x006FE484, 0, 0, 0x00050000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_010) {
  float src_float = 0.00000000000000000000000000013929383838292f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {.bits = {0x00000001, 0, 0, 0x001C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_011) {
  float src_float = 0.000000000000000000000000000000001939293838382f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {.bits = {0, 0, 0, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(1, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_015) {
  float src_float = 0.00000000000000000000000005646473736464f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {.bits = {0x00000235, 0, 0, 0x001C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_022) {
  float src_float = -1.307818E+07f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00C78EA4, 0x00000000, 0x00000000, 0x80000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_023) {
  float src_float = -30914.76f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x002F2C14, 0x00000000, 0x00000000, 0x80020000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_028) {
  float src_float = 0.00000000000000000000000000016929383838292f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {.bits = {0x00000002, 0, 0, 0x001C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_030) {
  float src_float = 3.693497E-09f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00385BB9, 0x00000000, 0x00000000, 0x000F0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_031) {
  float src_float = 351871.4f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0035B0FA, 0x00000000, 0x00000000, 0x00010000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_032) {
  float src_float = 0.1175977f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0011F1A9, 0x00000000, 0x00000000, 0x00070000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_033) {
  float src_float = -2.013319E-14f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x001EB887, 0x00000000, 0x00000000, 0x80140000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_034) {
  float src_float = -280.7036f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x002AD4FC, 0x00000000, 0x00000000, 0x80040000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_039) {
  float src_float = 4.511203E-27f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0000002D, 0x00000000, 0x00000000, 0x001C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_042) {
  float src_float = -5.447201E-28f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00000005, 0x00000000, 0x00000000, 0x801C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_045) {
  float src_float = 1.325723E-09f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00143A9B, 0x00000000, 0x00000000, 0x000F0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_047) {
  float src_float = -1.337444E-22f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00146864, 0x00000000, 0x00000000, 0x801C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_053) {
  float src_float = -3.22218E-27f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00000020, 0x00000000, 0x00000000, 0x801C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_054) {
  float src_float = 1.290434E-09f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0013B0C2, 0x00000000, 0x00000000, 0x000F0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_055) {
  float src_float = -1.162378E-20f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0011BC8A, 0x00000000, 0x00000000, 0x801A0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_057) {
  float src_float = -2.747507E-06f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0029EC73, 0x00000000, 0x00000000, 0x800C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_058) {
  float src_float = -2.233666E-28f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00000002, 0x00000000, 0x00000000, 0x801C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_059) {
  float src_float = -9.564972E-05f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0091F32C, 0x00000000, 0x00000000, 0x800B0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_062) {
  float src_float = 1.248784E-11f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00130E10, 0x00000000, 0x00000000, 0x00110000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_063) {
  float src_float = 3.830389E-28f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00000004, 0x00000000, 0x00000000, 0x001C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_067) {
  float src_float = -0.005833615f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0059038F, 0x00000000, 0x00000000, 0x80090000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_071) {
  float src_float = -1.381688E-13f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00151538, 0x00000000, 0x00000000, 0x80130000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_074) {
  float src_float = 0.01434358f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0015E2F6, 0x00000000, 0x00000000, 0x00080000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_076) {
  float src_float = 2.963941E-09f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x002D39E5, 0x00000000, 0x00000000, 0x000F0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_077) {
  float src_float = -4.554593f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00457F61, 0x00000000, 0x00000000, 0x80060000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_078) {
  float src_float = 1.511913E-20f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x001711E9, 0x00000000, 0x00000000, 0x001A0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_079) {
  float src_float = 12.18852f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00129924, 0x00000000, 0x00000000, 0x00050000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_081) {
  float src_float = -0.7325138f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x006FC5D2, 0x00000000, 0x00000000, 0x80070000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_082) {
  float src_float = 49394.41f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x004B5EB1, 0x00000000, 0x00000000, 0x00020000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_083) {
  float src_float = 0.0002621874f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x002801B2, 0x00000000, 0x00000000, 0x000A0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_085) {
  float src_float = -7.048725E-24f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00011357, 0x00000000, 0x00000000, 0x801C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_086) {
  float src_float = 1.661392E-16f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x001959D0, 0x00000000, 0x00000000, 0x00160000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_092) {
  float src_float = -0.2220105f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0021E049, 0x00000000, 0x00000000, 0x80070000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_097) {
  float src_float = -5.937755E-18f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x005A9A5B, 0x00000000, 0x00000000, 0x80180000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_098) {
  float src_float = 9.214601E-09f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x008C9A89, 0x00000000, 0x00000000, 0x000F0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_100) {
  float src_float = -0.2386963f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00246C13, 0x00000000, 0x00000000, 0x80070000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_101) {
  float src_float = -4.803305E-20f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00494AE9, 0x00000000, 0x00000000, 0x801A0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_106) {
  float src_float = 2.011937E-05f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x001EB321, 0x00000000, 0x00000000, 0x000B0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_108) {
  float src_float = -3.577309f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x003695DD, 0x00000000, 0x00000000, 0x80060000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_109) {
  float src_float = -0.01349936f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00149930, 0x00000000, 0x00000000, 0x80080000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_113) {
  float src_float = 2.03361E-23f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00031A61, 0x00000000, 0x00000000, 0x001C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_115) {
  float src_float = -4.087111E-10f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x003E5D47, 0x00000000, 0x00000000, 0x80100000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_118) {
  float src_float = -1.351883E-11f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0014A0CB, 0x00000000, 0x00000000, 0x80110000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_120) {
  float src_float = -1.655359E-07f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0019423F, 0x00000000, 0x00000000, 0x800D0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_121) {
  float src_float = -2.818527E-09f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x002B01DF, 0x00000000, 0x00000000, 0x800F0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_122) {
  float src_float = 2.024663E-23f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x000316E2, 0x00000000, 0x00000000, 0x001C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_123) {
  float src_float = 2.310628E-10f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x002341E4, 0x00000000, 0x00000000, 0x00100000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_124) {
  float src_float = 2968.287f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x002D4ADF, 0x00000000, 0x00000000, 0x00030000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_125) {
  float src_float = 1.229755E-18f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0012C3BB, 0x00000000, 0x00000000, 0x00180000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_126) {
  float src_float = 1.059234E-14f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x001029A2, 0x00000000, 0x00000000, 0x00140000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_127) {
  float src_float = -64208.49f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0061F971, 0x00000000, 0x00000000, 0x80020000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_129) {
  float src_float = -2.191804E+07f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x014E7158, 0x00000000, 0x00000000, 0x80000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_130) {
  float src_float = 6.5419E-24f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0000FF8B, 0x00000000, 0x00000000, 0x001C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_135) {
  float src_float = 0.2616035f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0027EAE3, 0x00000000, 0x00000000, 0x00070000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_137) {
  float src_float = -4.61851E-24f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0000B469, 0x00000000, 0x00000000, 0x801C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_138) {
  float src_float = -0.003898347f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x003B7BEB, 0x00000000, 0x00000000, 0x80090000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_139) {
  float src_float = 11.08692f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0010EAD4, 0x00000000, 0x00000000, 0x00050000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_140) {
  float src_float = -0.003970314f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x003C950A, 0x00000000, 0x00000000, 0x80090000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_141) {
  float src_float = 1.054338E-15f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00101682, 0x00000000, 0x00000000, 0x00150000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_142) {
  float src_float = -32.53767f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0031A607, 0x00000000, 0x00000000, 0x80050000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_145) {
  float src_float = 2.324943E-28f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00000002, 0x00000000, 0x00000000, 0x001C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_146) {
  float src_float = 3191.227f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0030B1BB, 0x00000000, 0x00000000, 0x00030000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_148) {
  float src_float = -3.894784E-17f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x003B6E00, 0x00000000, 0x00000000, 0x80170000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_152) {
  float src_float = 1.069406E-20f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0010515E, 0x00000000, 0x00000000, 0x001A0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_153) {
  float src_float = 1963320.0f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x001DF538, 0x00000000, 0x00000000, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_154) {
  float src_float = 1631.409f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0018E4B1, 0x00000000, 0x00000000, 0x00030000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_155) {
  float src_float = -9.583782E-09f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00923CA6, 0x00000000, 0x00000000, 0x800F0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_157) {
  float src_float = 10.23795f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x000F9F33, 0x00000000, 0x00000000, 0x00050000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_158) {
  float src_float = -703088.8f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x006B4868, 0x00000000, 0x00000000, 0x80010000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_160) {
  float src_float = 0.0001655871f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0019443F, 0x00000000, 0x00000000, 0x000A0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_163) {
  float src_float = -1.617612E-26f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x000000A2, 0x00000000, 0x00000000, 0x801C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_164) {
  float src_float = -212.0078f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0020598E, 0x00000000, 0x00000000, 0x80040000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_165) {
  float src_float = 1.683534E-20f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0019B04E, 0x00000000, 0x00000000, 0x001A0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_169) {
  float src_float = 2.241625E-06f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00223459, 0x00000000, 0x00000000, 0x000C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_170) {
  float src_float = -1.303562E-27f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0000000D, 0x00000000, 0x00000000, 0x801C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_171) {
  float src_float = 3.300137E-28f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00000003, 0x00000000, 0x00000000, 0x001C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_173) {
  float src_float = -1.335107E-17f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00145F43, 0x00000000, 0x00000000, 0x80170000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_176) {
  float src_float = 9283997.0f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x008DA99D, 0x00000000, 0x00000000, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_177) {
  float src_float = -5.917783E-20f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x005A4C57, 0x00000000, 0x00000000, 0x801A0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_178) {
  float src_float = -4.605351E-08f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x004645A7, 0x00000000, 0x00000000, 0x800E0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_181) {
  float src_float = -4.665166E-28f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00000005, 0x00000000, 0x00000000, 0x801C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_184) {
  float src_float = 0.01401084f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x001560FC, 0x00000000, 0x00000000, 0x00080000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_185) {
  float src_float = 16.07887f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x001888CF, 0x00000000, 0x00000000, 0x00050000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_189) {
  float src_float = -1.272028E-09f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x001368DC, 0x00000000, 0x00000000, 0x800F0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_190) {
  float src_float = -5.217951E-12f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x004F9E9F, 0x00000000, 0x00000000, 0x80120000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_191) {
  float src_float = -386648.3f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x003AFF73, 0x00000000, 0x00000000, 0x80010000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_193) {
  float src_float = -109.3412f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0010AF24, 0x00000000, 0x00000000, 0x80040000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_199) {
  float src_float = -2.262675E-19f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00228693, 0x00000000, 0x00000000, 0x80190000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_200) {
  float src_float = 2.464824E-20f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00259C38, 0x00000000, 0x00000000, 0x001A0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_201) {
  float src_float = 1.511738E-07f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0017113A, 0x00000000, 0x00000000, 0x000D0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_202) {
  float src_float = 1.720869E-06f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x001A4225, 0x00000000, 0x00000000, 0x000C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_203) {
  float src_float = 8.188374E-27f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00000052, 0x00000000, 0x00000000, 0x001C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_204) {
  float src_float = -10.51995f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00100D5B, 0x00000000, 0x00000000, 0x80050000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_206) {
  float src_float = 119471.1f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00123AD7, 0x00000000, 0x00000000, 0x00010000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_211) {
  float src_float = -2.851002E-18f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x002B80BA, 0x00000000, 0x00000000, 0x80180000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_212) {
  float src_float = 112195.3f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00111EA1, 0x00000000, 0x00000000, 0x00010000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_213) {
  float src_float = 1.039634E+08f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x06325B08, 0x00000000, 0x00000000, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_217) {
  float src_float = -0.001798262f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x001B7076, 0x00000000, 0x00000000, 0x80090000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_219) {
  float src_float = -3.263142E-13f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0031CAA6, 0x00000000, 0x00000000, 0x80130000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_220) {
  float src_float = 1.231812E-27f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0000000C, 0x00000000, 0x00000000, 0x001C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_223) {
  float src_float = -1.322553E-20f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00142E39, 0x00000000, 0x00000000, 0x801A0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_224) {
  float src_float = 1.148738E+08f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x06D8D5C8, 0x00000000, 0x00000000, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_226) {
  float src_float = 884496.5f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0086F6A5, 0x00000000, 0x00000000, 0x00010000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_227) {
  float src_float = 4.103006E-27f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00000029, 0x00000000, 0x00000000, 0x001C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_228) {
  float src_float = 4.647867E-26f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x000001D1, 0x00000000, 0x00000000, 0x001C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_231) {
  float src_float = -0.6512141f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00635E0D, 0x00000000, 0x00000000, 0x80070000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_233) {
  float src_float = 5.061718E-20f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x004D3C56, 0x00000000, 0x00000000, 0x001A0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_235) {
  float src_float = -1.918654E-19f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x001D46BE, 0x00000000, 0x00000000, 0x80190000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_236) {
  float src_float = -1.215304E-18f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00128B48, 0x00000000, 0x00000000, 0x80180000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_241) {
  float src_float = 3.866995E-25f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00000F1B, 0x00000000, 0x00000000, 0x001C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_242) {
  float src_float = 44301.02f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00439916, 0x00000000, 0x00000000, 0x00020000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_243) {
  float src_float = 2.47909E-26f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x000000F8, 0x00000000, 0x00000000, 0x001C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_244) {
  float src_float = -3.094722E-11f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x002F38C2, 0x00000000, 0x00000000, 0x80110000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_245) {
  float src_float = -0.0001411886f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00158B2E, 0x00000000, 0x00000000, 0x800A0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_248) {
  float src_float = -1.663049E-18f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00196049, 0x00000000, 0x00000000, 0x80180000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_250) {
  float src_float = 7.748195E-06f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00763A63, 0x00000000, 0x00000000, 0x000C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST
START_TEST(s21_from_int_to_decimal_01) {
  int src_int = 0;
  s21_decimal etalon_decimal = {.bits = {0, 0, 0, 0x00000000}}, dst_decimal;
  int s21_error = s21_from_int_to_decimal(src_int, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon_decimal.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_int_to_decimal_02) {
  int src_int = 1;
  s21_decimal etalon_decimal = {.bits = {1, 0, 0, 0x00000000}}, dst_decimal;
  int s21_error = s21_from_int_to_decimal(src_int, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon_decimal.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_int_to_decimal_03) {
  int src_int = -1;
  s21_decimal etalon_decimal = {.bits = {1, 0, 0, 0x80000000}}, dst_decimal;
  int s21_error = s21_from_int_to_decimal(src_int, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon_decimal.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_int_to_decimal_04) {
  int src_int = INT_MAX;
  s21_decimal etalon_decimal = {.bits = {INT_MAX, 0, 0, 0x00000000}},
              dst_decimal;
  int s21_error = s21_from_int_to_decimal(src_int, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon_decimal.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_int_to_decimal_05) {
  int src_int = INT_MIN;
  s21_decimal etalon_decimal = {.bits = {2147483648U, 0, 0, 0x80000000}},
              dst_decimal;
  int s21_error = s21_from_int_to_decimal(src_int, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon_decimal.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_int_to_decimal_06) {
  int src_int = -12345;
  s21_decimal etalon_decimal = {.bits = {12345, 0, 0, 0x80000000}}, dst_decimal;
  int s21_error = s21_from_int_to_decimal(src_int, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon_decimal.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_int_to_decimal_07) {
  int src_int = 12345;
  s21_decimal etalon_decimal = {.bits = {12345, 0, 0, 0x00000000}}, dst_decimal;
  int s21_error = s21_from_int_to_decimal(src_int, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon_decimal.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_int_to_decimal_08) {
  int src_int = -0;
  s21_decimal etalon_decimal = {.bits = {0, 0, 0, 0x00000000}}, dst_decimal;
  int s21_error = s21_from_int_to_decimal(src_int, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon_decimal.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_int_to_decimal_09) {
  int src_int = 32167;
  s21_decimal etalon_decimal = {.bits = {32167, 0, 0, 0x00000000}}, dst_decimal;
  int s21_error = s21_from_int_to_decimal(src_int, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon_decimal.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_int_to_decimal_10) {
  int src_int = -32167;
  s21_decimal etalon_decimal = {.bits = {32167, 0, 0, 0x80000000}}, dst_decimal;
  int s21_error = s21_from_int_to_decimal(src_int, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon_decimal.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_int_to_decimal_11) {
  int src_int = -43543;
  s21_decimal etalon_decimal = {.bits = {43543, 0, 0, 0x80000000}}, dst_decimal;
  int s21_error = s21_from_int_to_decimal(src_int, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon_decimal.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_int_to_decimal_12) {
  int src_int = 43543;
  s21_decimal etalon_decimal = {.bits = {43543, 0, 0, 0x00000000}}, dst_decimal;
  int s21_error = s21_from_int_to_decimal(src_int, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon_decimal.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_int_to_decimal_13) {
  int src_int = -32767;
  s21_decimal etalon_decimal = {.bits = {32767, 0, 0, 0x80000000}}, dst_decimal;
  int s21_error = s21_from_int_to_decimal(src_int, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon_decimal.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_int_to_decimal_14) {
  int src_int = 32767;
  s21_decimal etalon_decimal = {.bits = {32767, 0, 0, 0x00000000}}, dst_decimal;
  int s21_error = s21_from_int_to_decimal(src_int, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon_decimal.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_int_to_decimal_15) {
  int src_int = -123456;
  s21_decimal etalon_decimal = {.bits = {123456, 0, 0, 0x80000000}},
              dst_decimal;
  int s21_error = s21_from_int_to_decimal(src_int, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon_decimal.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_int_to_decimal_16) {
  int src_int = 123456;
  s21_decimal etalon_decimal = {.bits = {123456, 0, 0, 0x00000000}},
              dst_decimal;
  int s21_error = s21_from_int_to_decimal(src_int, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon_decimal.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_int_to_decimal_17) {
  int src_int = -320167;
  s21_decimal etalon_decimal = {.bits = {320167, 0, 0, 0x80000000}},
              dst_decimal;
  int s21_error = s21_from_int_to_decimal(src_int, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon_decimal.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_int_to_decimal_18) {
  int src_int = 320167;
  s21_decimal etalon_decimal = {.bits = {320167, 0, 0, 0x00000000}},
              dst_decimal;
  int s21_error = s21_from_int_to_decimal(src_int, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon_decimal.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_int_to_decimal_19) {
  int src_int = -1234567890;
  s21_decimal etalon_decimal = {.bits = {1234567890, 0, 0, 0x80000000}},
              dst_decimal;
  int s21_error = s21_from_int_to_decimal(src_int, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon_decimal.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_int_to_decimal_20) {
  int src_int = 1234567890;
  s21_decimal etalon_decimal = {.bits = {1234567890, 0, 0, 0x00000000}},
              dst_decimal;
  int s21_error = s21_from_int_to_decimal(src_int, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon_decimal.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

Suite *test_s21_conversion(void) {
  Suite *s = suite_create("s21_converter");
  TCase *tc = tcase_create("s21_converter");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_from_decimal_to_float_01);
  tcase_add_test(tc, s21_from_decimal_to_float_02);
  tcase_add_test(tc, s21_from_decimal_to_float_03);
  tcase_add_test(tc, s21_from_decimal_to_float_04);
  tcase_add_test(tc, s21_from_decimal_to_float_05);
  tcase_add_test(tc, s21_from_decimal_to_float_06);
  tcase_add_test(tc, s21_from_decimal_to_float_07);
  tcase_add_test(tc, s21_from_decimal_to_float_08);
  tcase_add_test(tc, s21_from_decimal_to_float_09);
  tcase_add_test(tc, s21_from_decimal_to_float_10);
  tcase_add_test(tc, s21_from_decimal_to_int_01);
  tcase_add_test(tc, s21_from_decimal_to_int_02);
  tcase_add_test(tc, s21_from_decimal_to_int_03);
  tcase_add_test(tc, s21_from_decimal_to_int_04);
  tcase_add_test(tc, s21_from_decimal_to_int_06);
  tcase_add_test(tc, s21_from_decimal_to_int_05);
  tcase_add_test(tc, s21_from_decimal_to_int_07);
  tcase_add_test(tc, s21_from_decimal_to_int_08);
  tcase_add_test(tc, s21_from_decimal_to_int_09);
  tcase_add_test(tc, s21_from_decimal_to_int_10);
  tcase_add_test(tc, s21_from_decimal_to_int_11);
  tcase_add_test(tc, s21_from_decimal_to_int_12);
  tcase_add_test(tc, s21_from_decimal_to_int_13);
  tcase_add_test(tc, s21_from_decimal_to_int_15);
  tcase_add_test(tc, s21_from_decimal_to_int_16);
  tcase_add_test(tc, s21_from_decimal_to_int_17);
  tcase_add_test(tc, s21_from_decimal_to_int_18);
  tcase_add_test(tc, s21_from_decimal_to_int_19);
  tcase_add_test(tc, s21_from_decimal_to_int_20);
  tcase_add_test(tc, s21_from_float_to_decimal_001);
  tcase_add_test(tc, s21_from_float_to_decimal_002);
  tcase_add_test(tc, s21_from_float_to_decimal_003);
  tcase_add_test(tc, s21_from_float_to_decimal_007);
  tcase_add_test(tc, s21_from_float_to_decimal_010);
  tcase_add_test(tc, s21_from_float_to_decimal_011);
  tcase_add_test(tc, s21_from_float_to_decimal_015);
  tcase_add_test(tc, s21_from_float_to_decimal_022);
  tcase_add_test(tc, s21_from_float_to_decimal_023);
  tcase_add_test(tc, s21_from_float_to_decimal_028);
  tcase_add_test(tc, s21_from_float_to_decimal_030);
  tcase_add_test(tc, s21_from_float_to_decimal_031);
  tcase_add_test(tc, s21_from_float_to_decimal_032);
  tcase_add_test(tc, s21_from_float_to_decimal_033);
  tcase_add_test(tc, s21_from_float_to_decimal_034);
  tcase_add_test(tc, s21_from_float_to_decimal_039);
  tcase_add_test(tc, s21_from_float_to_decimal_042);
  tcase_add_test(tc, s21_from_float_to_decimal_045);
  tcase_add_test(tc, s21_from_float_to_decimal_047);
  tcase_add_test(tc, s21_from_float_to_decimal_053);
  tcase_add_test(tc, s21_from_float_to_decimal_054);
  tcase_add_test(tc, s21_from_float_to_decimal_055);
  tcase_add_test(tc, s21_from_float_to_decimal_057);
  tcase_add_test(tc, s21_from_float_to_decimal_058);
  tcase_add_test(tc, s21_from_float_to_decimal_059);
  tcase_add_test(tc, s21_from_float_to_decimal_062);
  tcase_add_test(tc, s21_from_float_to_decimal_063);
  tcase_add_test(tc, s21_from_float_to_decimal_067);
  tcase_add_test(tc, s21_from_float_to_decimal_071);
  tcase_add_test(tc, s21_from_float_to_decimal_074);
  tcase_add_test(tc, s21_from_float_to_decimal_076);
  tcase_add_test(tc, s21_from_float_to_decimal_077);
  tcase_add_test(tc, s21_from_float_to_decimal_078);
  tcase_add_test(tc, s21_from_float_to_decimal_079);
  tcase_add_test(tc, s21_from_float_to_decimal_081);
  tcase_add_test(tc, s21_from_float_to_decimal_082);
  tcase_add_test(tc, s21_from_float_to_decimal_083);
  tcase_add_test(tc, s21_from_float_to_decimal_085);
  tcase_add_test(tc, s21_from_float_to_decimal_086);
  tcase_add_test(tc, s21_from_float_to_decimal_092);
  tcase_add_test(tc, s21_from_float_to_decimal_097);
  tcase_add_test(tc, s21_from_float_to_decimal_098);
  tcase_add_test(tc, s21_from_float_to_decimal_100);
  tcase_add_test(tc, s21_from_float_to_decimal_101);
  tcase_add_test(tc, s21_from_float_to_decimal_106);
  tcase_add_test(tc, s21_from_float_to_decimal_108);
  tcase_add_test(tc, s21_from_float_to_decimal_109);
  tcase_add_test(tc, s21_from_float_to_decimal_113);
  tcase_add_test(tc, s21_from_float_to_decimal_115);
  tcase_add_test(tc, s21_from_float_to_decimal_118);
  tcase_add_test(tc, s21_from_float_to_decimal_120);
  tcase_add_test(tc, s21_from_float_to_decimal_121);
  tcase_add_test(tc, s21_from_float_to_decimal_122);
  tcase_add_test(tc, s21_from_float_to_decimal_123);
  tcase_add_test(tc, s21_from_float_to_decimal_124);
  tcase_add_test(tc, s21_from_float_to_decimal_125);
  tcase_add_test(tc, s21_from_float_to_decimal_126);
  tcase_add_test(tc, s21_from_float_to_decimal_127);
  tcase_add_test(tc, s21_from_float_to_decimal_129);
  tcase_add_test(tc, s21_from_float_to_decimal_130);
  tcase_add_test(tc, s21_from_float_to_decimal_135);
  tcase_add_test(tc, s21_from_float_to_decimal_137);
  tcase_add_test(tc, s21_from_float_to_decimal_138);
  tcase_add_test(tc, s21_from_float_to_decimal_139);
  tcase_add_test(tc, s21_from_float_to_decimal_140);
  tcase_add_test(tc, s21_from_float_to_decimal_141);
  tcase_add_test(tc, s21_from_float_to_decimal_142);
  tcase_add_test(tc, s21_from_float_to_decimal_145);
  tcase_add_test(tc, s21_from_float_to_decimal_146);
  tcase_add_test(tc, s21_from_float_to_decimal_148);
  tcase_add_test(tc, s21_from_float_to_decimal_152);
  tcase_add_test(tc, s21_from_float_to_decimal_153);
  tcase_add_test(tc, s21_from_float_to_decimal_154);
  tcase_add_test(tc, s21_from_float_to_decimal_155);
  tcase_add_test(tc, s21_from_float_to_decimal_157);
  tcase_add_test(tc, s21_from_float_to_decimal_158);
  tcase_add_test(tc, s21_from_float_to_decimal_160);
  tcase_add_test(tc, s21_from_float_to_decimal_163);
  tcase_add_test(tc, s21_from_float_to_decimal_164);
  tcase_add_test(tc, s21_from_float_to_decimal_165);
  tcase_add_test(tc, s21_from_float_to_decimal_169);
  tcase_add_test(tc, s21_from_float_to_decimal_170);
  tcase_add_test(tc, s21_from_float_to_decimal_171);
  tcase_add_test(tc, s21_from_float_to_decimal_173);
  tcase_add_test(tc, s21_from_float_to_decimal_176);
  tcase_add_test(tc, s21_from_float_to_decimal_177);
  tcase_add_test(tc, s21_from_float_to_decimal_178);
  tcase_add_test(tc, s21_from_float_to_decimal_181);

  tcase_add_test(tc, s21_from_float_to_decimal_184);
  tcase_add_test(tc, s21_from_float_to_decimal_185);

  tcase_add_test(tc, s21_from_float_to_decimal_189);
  tcase_add_test(tc, s21_from_float_to_decimal_190);
  tcase_add_test(tc, s21_from_float_to_decimal_191);

  tcase_add_test(tc, s21_from_float_to_decimal_193);

  tcase_add_test(tc, s21_from_float_to_decimal_199);
  tcase_add_test(tc, s21_from_float_to_decimal_200);
  tcase_add_test(tc, s21_from_float_to_decimal_201);
  tcase_add_test(tc, s21_from_float_to_decimal_202);
  tcase_add_test(tc, s21_from_float_to_decimal_203);
  tcase_add_test(tc, s21_from_float_to_decimal_204);

  tcase_add_test(tc, s21_from_float_to_decimal_206);

  tcase_add_test(tc, s21_from_float_to_decimal_211);
  tcase_add_test(tc, s21_from_float_to_decimal_212);
  tcase_add_test(tc, s21_from_float_to_decimal_213);

  tcase_add_test(tc, s21_from_float_to_decimal_217);

  tcase_add_test(tc, s21_from_float_to_decimal_219);
  tcase_add_test(tc, s21_from_float_to_decimal_220);

  tcase_add_test(tc, s21_from_float_to_decimal_223);
  tcase_add_test(tc, s21_from_float_to_decimal_224);

  tcase_add_test(tc, s21_from_float_to_decimal_226);
  tcase_add_test(tc, s21_from_float_to_decimal_227);
  tcase_add_test(tc, s21_from_float_to_decimal_228);

  tcase_add_test(tc, s21_from_float_to_decimal_231);

  tcase_add_test(tc, s21_from_float_to_decimal_233);

  tcase_add_test(tc, s21_from_float_to_decimal_235);
  tcase_add_test(tc, s21_from_float_to_decimal_236);

  tcase_add_test(tc, s21_from_float_to_decimal_241);
  tcase_add_test(tc, s21_from_float_to_decimal_242);
  tcase_add_test(tc, s21_from_float_to_decimal_243);
  tcase_add_test(tc, s21_from_float_to_decimal_244);
  tcase_add_test(tc, s21_from_float_to_decimal_245);

  tcase_add_test(tc, s21_from_float_to_decimal_248);

  tcase_add_test(tc, s21_from_float_to_decimal_250);
  tcase_add_test(tc, s21_from_int_to_decimal_01);
  tcase_add_test(tc, s21_from_int_to_decimal_02);
  tcase_add_test(tc, s21_from_int_to_decimal_03);
  tcase_add_test(tc, s21_from_int_to_decimal_04);
  tcase_add_test(tc, s21_from_int_to_decimal_05);
  tcase_add_test(tc, s21_from_int_to_decimal_06);
  tcase_add_test(tc, s21_from_int_to_decimal_07);
  tcase_add_test(tc, s21_from_int_to_decimal_08);
  tcase_add_test(tc, s21_from_int_to_decimal_09);
  tcase_add_test(tc, s21_from_int_to_decimal_10);
  tcase_add_test(tc, s21_from_int_to_decimal_11);
  tcase_add_test(tc, s21_from_int_to_decimal_12);
  tcase_add_test(tc, s21_from_int_to_decimal_13);
  tcase_add_test(tc, s21_from_int_to_decimal_14);
  tcase_add_test(tc, s21_from_int_to_decimal_15);
  tcase_add_test(tc, s21_from_int_to_decimal_16);
  tcase_add_test(tc, s21_from_int_to_decimal_17);
  tcase_add_test(tc, s21_from_int_to_decimal_18);
  tcase_add_test(tc, s21_from_int_to_decimal_19);
  tcase_add_test(tc, s21_from_int_to_decimal_20);
  return s;
}
