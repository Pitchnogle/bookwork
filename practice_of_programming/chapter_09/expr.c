/**
A simple reverse polish (rpn) calculator

This is an example (with enhancements) of code listed in chapter 4 of the book,
"The C Programming Language" 2nd ed. by Kernighan & Ritchie.

This program supports the operators:
+ (addition)
- (subtraction)
* (multiplication)
/ (division)
% (modulus)
^ (exponentiation)

For example:
./expr 17 5 % -8 10 + 2.3 ^ .5 "*" /
	0.81225240

This is equivalent to the expression:
(17 % 5) / ((-8 + 10)^2.5 * 0.5)

This version also adds in some trigonomic functions. With the conversion to use
strings via the command-line, now it is very simple to add new commands.

For example:
2 pi * cos
	1.00000000
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// -----------------------------------------------------------------------------
// Definitions
// -----------------------------------------------------------------------------

#define NUMBER      ('0')  /* Code represents number read in getop()          */
#define STACK_DEPTH (100)  /* Max number of values in the stack               */

// -----------------------------------------------------------------------------
// Function Prototypes
// -----------------------------------------------------------------------------

int is_number(char *s);

void push(double f);
double pop(void);

// -----------------------------------------------------------------------------
// Global Variables
// -----------------------------------------------------------------------------

static int sp = 0;
static double stack[STACK_DEPTH];

// =============================================================================
// Main Program
// =============================================================================

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
  int i, type;
  double op2;

  char buf[BUF_SIZE];

  while (fgets(buf, sizeof (buf), stdin) != NULL) {
    // Null-terminate to remove the newline
    buf[strlen(buf) - 1] = '\0';

    char *pch;
    pch = strtok(buf, " ");
    
    // Process this token
    while (NULL != pch) {
      if (strcmp(pch, "+") == 0) {
        push(pop() + pop());
      }
      else if (strcmp(pch, "*") == 0) {
        push(pop() * pop());
      }
      else if (strcmp(pch, "-") == 0) {
        op2 = pop();
        push(pop() - op2);
      }
      else if (strcmp(pch, "/") == 0) {
        op2 = pop();
        if (op2 != 0.0)
          push(pop() / op2);
        else
          printf("expr: error -- zero division\n");
      }
      else if (strcmp(pch, "%") == 0) {
        push(fmod(pop(), pop())); // the % operator doesn't work on doubles hence fmod()
      }
      else if (strcmp(pch, "^") == 0) {
        push(pow(pop(), pop())); // matlab style exponentiation
      }
      else if (strcmp(pch, "pi") == 0) {
        push(3.14159265359);
      }
      else if (strcmp(pch, "sin") == 0) {
        push(sin(pop()));
      }
      else if (strcmp(pch, "cos") == 0) {
        push(cos(pop()));
      }
      else {
        if (is_number(pch))
          push(atof(pch));
        else
          printf("expr: error -- unknown command <%s>\n", pch);
      }

      // Get the next token
      pch = strtok(NULL, " ");
    }
    printf("\t%.8f\n", pop());
  }

  return 0;
}

// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Local Functions
// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

int is_number(char *s)
{
  if (!isdigit(s[0]) && s[0] != '.' && s[0] != '-')
    return 0;
  else
    return 1;
}


void push(double f)
{
  if (sp < STACK_DEPTH)
    stack[sp++] = f;
  else
    printf("expr: error -- stack full!\n");
}


double pop(void)
{
  if (sp > 0)
    return stack[--sp];
  else {
    printf("expr: error -- stack empty!\n");
    return 0.0;
  }
}
