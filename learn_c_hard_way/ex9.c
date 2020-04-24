#include <stdio.h>

int main(int argc, char *arg[])
{
  int i = 0;
  while (i < 255) {
    printf("%d", i);
    i++;
  }

  // you need to add a final newline
  printf("\n");

  return 0;
}
