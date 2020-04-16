#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "csv.h"

// =============================================================================
// Main Program
// =============================================================================

int main()
{
  char *line;

  while ((line = csv_getline(stdin)) != NULL) {
    int i;
    int n = csv_nfield();
    for (i = 0; i < n; i++) {
      printf("%s%s", csv_field(i), i == n - 1 ? "\n" : ",");
    }
  }

  return 0;
}
