#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "pack_unpack.h"

// -----------------------------------------------------------------------------
// Function Prototypes
// -----------------------------------------------------------------------------

void clear_buf();

void test_pack_unpack_char();
void test_pack_unpack_u8();
void test_pack_unpack_i8();

void test_pack_unpack_u16();
void test_pack_unpack_i16();

void test_pack_unpack_u32();
void test_pack_unpack_i32();

void test_pack_unpack_float();
void test_pack_unpack_str();

void test_pack_unpack_multi();

void print_results(const char *msg, bool pass);

// =============================================================================
// Main Program
// =============================================================================

uint8_t buf[1024];

int main()
{
  test_pack_unpack_char();
  test_pack_unpack_u8();
  test_pack_unpack_i8();

  test_pack_unpack_u16();
  test_pack_unpack_i16();

  test_pack_unpack_u32();
  test_pack_unpack_i32();

  test_pack_unpack_float();
  test_pack_unpack_str();

  test_pack_unpack_multi();

  return 0;
}

// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Local Functions
// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

void clear_buf()
{
  memset(buf, 0, sizeof (buf));
}

void test_pack_unpack_char()
{
  bool pass = true;

  char x_c[] = {'a', 'n', '_', '!'};
  char y_c[] = {0, 0, 0, 0};

  clear_buf();

  // We can also just loop
  int i;
  for (i = 0; i < 4; i++) {
    pack(buf + i, "c", x_c[i]);
  }

  for (i = 0; i < 4; i++) {
    unpack(buf + i, "c", &y_c[i]);
    pass = pass && x_c[i] == y_c[i];
  }

  print_results("Pack/Unpack char", pass);
}

void test_pack_unpack_u8()
{
  bool pass = true;

  uint8_t x_u8[] = {0x11, 0x22, 0x33, 0xff};
  uint8_t y_u8[] = {0, 0, 0, 0};

  clear_buf();

  pack(buf, "bbbb", x_u8[0], x_u8[1], x_u8[2], x_u8[3]);
  unpack(buf, "bbbb", &y_u8[0], &y_u8[1], &y_u8[2], &y_u8[3]);

  pass = pass && x_u8[0] == y_u8[0];
  pass = pass && x_u8[1] == y_u8[1];
  pass = pass && x_u8[2] == y_u8[2];
  pass = pass && x_u8[3] == y_u8[3];

  print_results("Pack/Unpack uint8_t", pass);
}

void test_pack_unpack_i8()
{
  bool pass = true;

  uint8_t x_i8[] = {-1, -128, 13, 127};
  uint8_t y_i8[] = {0, 0, 0, 0};

  clear_buf();

  int i;
  for (i = 0; i < 4; i++) {
    pack(buf + i, "b", x_i8[i]);
  }

  for (i = 0; i < 4; i++) {
    unpack(buf + i, "b", &y_i8[i]);
    pass == pass && x_i8[i] == y_i8[i];
  }

  print_results("Pack/Unpack int8_t", pass);
}

void test_pack_unpack_u16()
{
  bool pass = true;

  uint16_t x_u16[] = {0x1234, 0x5678, 0xffff, 0xaa55};
  uint16_t y_u16[] = {0, 0, 0, 0};

  clear_buf();

  int i;
  pack(buf, "hhhh", x_u16[0], x_u16[1], x_u16[2], x_u16[3]);

  for (i = 0; i < 4; i++) {
    unpack(buf + sizeof (uint16_t) * i, "h", &y_u16[i]);
    pass == pass && x_u16[i] == y_u16[i];
  }

  print_results("Pack/Unpack uint16_t", pass);
}

void test_pack_unpack_i16()
{
  bool pass = true;

  int16_t x_i16[] = {-1, -32768, -1234, 32767};
  int16_t y_i16[] = {0, 0, 0, 0};

  clear_buf();

  int i;
  pack(buf, "hhhh", x_i16[0], x_i16[1], x_i16[2], x_i16[3]);

  for (i = 0; i < 4; i++) {
    unpack(buf + sizeof (int16_t) * i, "h", &y_i16[i]);
    pass == pass && x_i16[i] == y_i16[i];
  }

  print_results("Pack/Unpack int16_t", pass);
}

void test_pack_unpack_u32()
{
  bool pass = true;

  uint32_t x_u32[] = {0x13572468, 0xaa5577cc, 0x12345678, 0xffffffff};
  uint32_t y_u32[] = {0, 0, 0, 0};

  clear_buf();

  int i;
  pack(buf, "iiii", x_u32[0], x_u32[1], x_u32[2], x_u32[3]);

  for (i = 0; i < 4; i++) {
    unpack(buf + sizeof (uint32_t) * i, "i", &y_u32[i]);
    pass == pass && x_u32[i] == y_u32[i];
  }

  print_results("Pack/Unpack uint32_t", pass);
}

void test_pack_unpack_i32()
{
  bool pass = true;

  int32_t x_i32[] = {-1, -2147483648, 2147483647, 13};
  int32_t y_i32[] = {0, 0, 0, 0};

  clear_buf();

  int i;
  pack(buf, "iiii", x_i32[0], x_i32[1], x_i32[2], x_i32[3]);

  for (i = 0; i < 4; i++) {
    unpack(buf + sizeof (int32_t) * i, "i", &y_i32[i]);
    pass == pass && x_i32[i] == y_i32[i];
  }

  print_results("Pack/Unpack int32_t", pass);
}

void test_pack_unpack_float()
{
  bool pass = true;

  float x_f[] = {
    1.27953441049492275497546944167E-28, // 0x11223344
    -1.94339031108467442524295876074E38, // 0xFF123456
    -6.259853398707798016E18,            // 0xDEADBEEF
    3.1415927410125732421875E0           // 0x40490FDB
  };

  float y_f[] = {0, 0, 0, 0};

  int i;
  pack(buf, "ffff", x_f[0], x_f[1], x_f[2], x_f[3]);

  for (i = 0; i < 4; i++) {
    unpack(buf + sizeof (float) * i, "f", &y_f[i]);
    pass == pass && x_f[i] == y_f[i];
  }

  print_results("Pack/Unpack float", pass);
}

void test_pack_unpack_str()
{
  bool pass = true;

  const char *wr_buf = "This is a TEST string!";
  char rd_buf[80];

  pack(buf, "s", wr_buf);
  unpack(buf, "s", rd_buf);

  pass = pass && strcmp(wr_buf, rd_buf) == 0;
  pass = pass && strlen(wr_buf) == strlen(rd_buf);

  print_results("Pack/Unpack string", pass);
}

void test_pack_unpack_multi()
{
  bool pass = true;

  uint8_t u8 = 0xa5;
  uint16_t u16 = 0xFEED;
  uint32_t u32 = 0x12345678;
  const char *wr_buf = "test me";
  float f = 3.1415927410125732421875E0;

  pack(buf, "bhisf", u8, u16, u32, wr_buf, f);

  uint8_t y8 = 0;
  uint16_t y16 = 0;
  uint32_t y32 = 0;
  char rd_buf[10] = {0};
  float y_f = 0;

  unpack(buf, "bhisf", &y8, &y16, &y32, rd_buf, &y_f);

  pass = pass && u8 == y8;
  pass = pass && u16 == y16;
  pass = pass && u32 == y32;
  pass = pass && strcmp(wr_buf, rd_buf) == 0;
  pass = pass && f == y_f;

  print_results("Pack/Unpack multi", pass);
}

void print_results(const char *msg, bool pass)
{
  printf("%s: ", msg);
  if (pass) {
    printf("\033[0;32mPassed\n"); // prints result in green
  }
  else {
    printf("\033[0;31mFailed\n"); // prints result in red
  }
  printf("\033[0m"); // reset output back to normal
}
