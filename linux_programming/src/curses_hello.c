#include <unistd.h>
#include <stdlib.h>
#include <curses.h>

int main()
{
  // curses programs must begin with this init call
  initscr();

  // Set cursor position to row 5, column 15
  move(5, 15);

  // Display our message
  printw("%s", "Hello, World!");

  // This causes the actual "virtual" window to update
  refresh();

  // Delay before ending program
  sleep(2);

  // curses programs end with this call
  endwin();
  
  return 0;
}