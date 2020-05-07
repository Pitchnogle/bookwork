/**
A simple reverse polish (rpn) calculator

This is an example (with enhancements) of code listed in chapter 4 of the book,
"The C Programming Language" 2nd ed. by Kernighan & Ritchie.

This program supports the operations:
+ (addition)
- (subtraction)
* (multiplication)
/ (division)
% (modulus)
^ (exponentiation)

For example:
17 5 % -8 10 + 2.3 ^ .5 * /
	0.81225240

This is equivalent to the expression:
(17 % 5) / ((-8 + 10)^2.5 * 0.5)

Once the [enter] is pressed, the expression is evaluated. Depending on the
number of operators entered, there may still be data on the stack which can
be operated on by subsequent expressions.

For example:
1 2 3 +
	5.00000000
4 +
	5.00000000
  
The stack had 1.0 on it at end of first expression. Enter ctrl-d to quit.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

// -----------------------------------------------------------------------------
// Definitions
// -----------------------------------------------------------------------------

#define MAXOP       (100)  /* Maximum operators in a command                  */
#define NUMBER      ('0')  /* Code represents number read in getop()          */

#define BUF_SIZE    (1000)  /* Buffer size used for getch()/ungetch()         */
#define STACK_DEPTH (1000)  /* Max number of values in the stack              */

// -----------------------------------------------------------------------------
// Function Prototypes
// -----------------------------------------------------------------------------

// IO functions
int getch(void);
void ungetch(int c);
int getop(char buf[]);

// Stack functions
void push(double f);
double pop(void);

// -----------------------------------------------------------------------------
// Global Variables
// -----------------------------------------------------------------------------

static int bufp = 0;
static char buf[BUF_SIZE];

static int sp = 0;
static double stack[STACK_DEPTH];

// =============================================================================
// Main Program
// =============================================================================

int main()
{
  int type;
  double op2;
  char s[MAXOP];
  
  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0)
        push(pop() / op2);
      else
        printf("calc: error -- zero division\n");
      break;
    case '%':
      push(fmod(pop(), pop())); // the % operator doesn't work on doubles hence fmod()
      break;
    case '^':
      push(pow(pop(), pop())); // matlab style exponentiation
      break;
    case '\n':
      printf("\t%.8f\n", pop());
      break;
    default:
      printf("calc: error -- unknown command\n");
      break;
    }
  }
}

// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Local Functions
// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

int getch(void)
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}


void ungetch(int c)
{
  if (bufp >= BUF_SIZE)
    printf("calc: ungetch() -- too many characters!\n");
  else
    buf[bufp++] = c;
}


int getop(char s[])
{
  int i,c;
  
  // Skip whitespace
  while((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  
  i = 0;
  // Is this an operator?
  if(!isdigit(c) && c != '.' && c != '-')
    return c;

  // Handle negative & fractions without leading digits
  if(c == '-')
    if(isdigit(c = getch()) || c == '.')
      s[++i] = c;
    else
    {
      if(c != EOF)
        ungetch(c);
      return '-';
    }
  
  // Handle digits before possible decimal point
  if(isdigit(c))
    while(isdigit(s[++i] = c = getch()))
      ;

  // Handle digits after decimal point
  if(c=='.')
    while(isdigit(s[++i] = c = getch()))
      ;
  
  s[i] = '\0';
  if(c != EOF)
    ungetch(c);
    
  return NUMBER;
}


void push(double f)
{
  if (sp < STACK_DEPTH)
    stack[sp++] = f;
  else
    printf("calc: error -- stack full!\n");
}


double pop(void)
{
  if (sp > 0)
    return stack[--sp];
  else {
    printf("calc: error -- stack empty!\n");
    return 0.0;
  }
}
