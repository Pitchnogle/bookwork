/*
This a simple test of string tokenization in C using strtok

When the program is run, the user would enter a line. The tokenization used here
is just spaces since it's meant to be part of an expression handler which could
be used by the RPN calc or the virtual machine.

Whatever is entered will be printed out one token per line. Type ctrl-d to quit.
*/
#include <stdio.h>
#include <string.h>

// =============================================================================
// Main Program
// =============================================================================

#define BUF_SIZE 1024

int main()
{
  char buf[BUF_SIZE];

  while (fgets(buf, sizeof (buf), stdin) != NULL) {
    char *pch;
    pch = strtok(buf, " ");
    while (NULL != pch) {
      printf("%s\n", pch);
      pch = strtok(NULL, " ");
    }
    printf("\n");
  }
}
