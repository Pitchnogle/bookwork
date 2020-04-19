#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "util.h"

// -----------------------------------------------------------------------------
// Function Prototypes
// -----------------------------------------------------------------------------

void hexdump(unsigned int addr_offset, char *buf, unsigned int len);

void vis(char *name, FILE *fin);

// =============================================================================
// Main Program
// =============================================================================

int main(int argc, char *argv[])
{
  int i;
  FILE *fin;

  setprogname("vis");
  if (argc == 1)
    eprintf("usage: vis filenames");
  else {
    for (i = 1; i < argc; i++) {
      if ((fin = fopen(argv[i], "rb")) == NULL)
        weprintf("can't open %s:", argv[i]);
      else {
        vis(argv[i], fin);
        fclose(fin);
      }
    }
  }
  printf("\n");

  return 0;
}

// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Local Functions
// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#define ROW_LEN 16

void hexdump(unsigned int addr_offset, char *buf, unsigned int len)
{
  int i;

  // Display the address offset
  printf("%08x  ", addr_offset);

  // Display the hex bytes
  for (i = 0; i < ROW_LEN; i++) {
    if (i < len)
      printf("%02x ", buf[i] & 0xff);
    else
      printf("   ");
    if (i == ROW_LEN / 2 - 1)
      printf(" ");
  }
  printf(" |");

  // Display same as ASCII
  for (i = 0; i < ROW_LEN; i++) {
    if (i < len)
      if (isprint(buf[i]))
        printf("%c", buf[i]);
      else
        printf(".");
    else
      printf(" ");
  }

  printf("|\n");
}

void vis(char *name, FILE *fin)
{
  int c, i;
  unsigned int addr_offset = 0;

  char buf[ROW_LEN];

  do {
    for (i = 0; (c = getc(fin)) != EOF; ) {
      buf[i++] = c;
      if (i % ROW_LEN == 0) {
        hexdump(addr_offset, buf, ROW_LEN);
        addr_offset += ROW_LEN;
        memset(buf, 0, ROW_LEN);
        i = 0;
      }
    }
  } while (c != EOF);

  // Display remaining buffer
  hexdump(addr_offset, buf, i);
}
