#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  srand(time(NULL));

  int i;
  for (i = 0; i < 256; i++) {
    int r = rand();
    printf("%010d, ", r);
    if (((i + 1) % 6) == 0) printf("\n");
  }
}
