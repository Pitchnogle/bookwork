#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>

#define PW_LEN   25
#define NAME_LEN 256

int main()
{
  char name[NAME_LEN];
  char password[PW_LEN];
  char *real_password = "xyzzy";
  int i = 0;

  initscr();

  move(5, 10);
  printw("%s", "Please login:");

  move(7, 10);
  printw("%s", "User name: ");
  getstr(name);

  move(9, 10);
  printw("%s", "Password: ");
  refresh();

  // Change to cbreak mode and turn off echo
  cbreak();
  noecho();

  memset(password, '\0', sizeof (password));
  while (i < PW_LEN) {
    password[i] = getch();
    move(9, 20 + i);
    addch('*');
    refresh();
    if (password[i] == '\n') break;
    if (strcmp(password, real_password) == 0) break;
    i++;
  }

  // restore echo and cooked mode
  echo();
  nocbreak();

  move(11, 10);
  if (strcmp(password, real_password) == 0)
    printw("%s", "Correct");
  else
    printw("%s", "Wrong");
  refresh();

  // Add delay so we can see result...
  sleep(2);

  endwin();

  return 0;
}
