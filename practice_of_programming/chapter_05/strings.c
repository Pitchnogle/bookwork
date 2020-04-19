#include <stdio.h>
#include <ctype.h>

#include "util.h"

// -----------------------------------------------------------------------------
// Function Prototypes
// -----------------------------------------------------------------------------

void strings(char *name, FILE *fin);

// =============================================================================
// Main Program
// =============================================================================

int main(int argc, char *argv[])
{
  int i;
  FILE *fin;

  setprogname("strings");
  if (argc == 1)
    eprintf("usage: strings filenames");
  else {
    for (i = 1; i < argc; i++) {
      if ((fin = fopen(argv[i], "rb")) == NULL)
        weprintf("can't open %s:", argv[i]);
      else {
        strings(argv[i], fin);
        fclose(fin);
      }
    }
  }
  return 0;
}

// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Local Functions
// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#define BUF_SIZE 80
#define MIN_LEN  6

// strings: extract printable strings from stream
void strings(char *name, FILE *fin)
{
  int c, i;
  char buf[BUF_SIZE];

  do {
    for (i = 0; (c = getc(fin)) != EOF; ) {
      if (!isprint(c))
        break;
      buf[i++] = c;
      if (i >= BUF_SIZE)
        break;
    }
    if (i >= MIN_LEN)
      printf("%s:%.*s\n", name, i, buf);
  } while (c != EOF);
}
