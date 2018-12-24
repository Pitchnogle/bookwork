#include <stdio.h>
#include <stdlib.h>

int main() {
  char card_name[3] = {0};
  int count = 0;
  while (card_name[0] != 'x') {
    puts("Enter the card name: ");
    scanf("%2s", card_name);

    int val = 0;
    switch (card_name[0]) {
    case 'k': case 'K':
    case 'q': case 'Q':
    case 'j': case 'J':
      val = 10;
      break;
    case 'a': case 'A':
      val = 11;
      break;
    case 'x':
      continue;
    default:
      val = atoi(card_name);
      if (val < 1 || val > 10) {
        puts("error");
        continue;
      }
      break;
    }

    if (val >= 3 && val <= 6) {
      count++;
    }
    else if (val == 10) {
      count--;
    }
    printf("Current count: %i\n", count);
  }

  return 0;
}