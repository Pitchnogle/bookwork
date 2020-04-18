#include <stdio.h>

#include "test_util.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

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
