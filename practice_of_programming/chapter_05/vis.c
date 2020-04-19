#include <stdio.h>
#include <ctype.h>

#include "util.h"

// -----------------------------------------------------------------------------
// Function Prototypes
// -----------------------------------------------------------------------------

void print_color_char(int c);

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


void print_color_char(int c)
{
  if (isprint(c))
    printf("%c", c);
  else
    // Display non-printable as blue '.'
    printf("\033[0;34m.\033[0m");
}

void vis(char *name, FILE *fin)
{
  int c, i;

  do {
    for (i = 0; (c = getc(fin)) != EOF; ) {
      print_color_char(c);
      if (i++ % 80 == 0)
        printf("\n");
    }
  } while (c != EOF);
}
