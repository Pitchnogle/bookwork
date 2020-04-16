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

  csv csv = csv_new();

  while ((line = csv_getline(csv, stdin)) != NULL) {
    int i;
    int n = csv_nfield(csv);
    for (i = 0; i < n; i++) {
      printf("%s%s", csv_field(csv, i), i == n - 1 ? "\n" : ",");
    }
  }

  return 0;
}
