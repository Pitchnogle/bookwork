/*

*/
#include <stdio.h>
#include <stdlib.h>

#include "util.h"

// -----------------------------------------------------------------------------
// Data Structures
// -----------------------------------------------------------------------------

typedef struct Symbol Symbol;
typedef struct Tree Tree;
typedef union Code Code;

struct Symbol {
  int value;
  char *name;
};

struct Tree {
  int op;         // operation code
  int value;      // value of number
  Symbol *symbol; // Symbol entry if variables
  Tree *left;
  Tree *right;
};

union Code {
  void (*op)(void); // function if operator
  int value;        // value if number
  Symbol *symbol;   // Symbol entry if variable
};

enum {
  NUMBER,
  VARIABLE,
  ADD,
  SUBTRACT,
  MULTIPLY,
  DIVIDE
  // etc.
};

// -----------------------------------------------------------------------------
// Function Prototypes
// -----------------------------------------------------------------------------

int generate(int codep, Tree *t);
int eval(Tree *t);

void pushop(void);
void pushsymop(void);
void addop(void);
void subop(void);
void multop(void);
void divop(void);

// =============================================================================
// Main Program
// =============================================================================

#define NCODE  100
#define NSTACK 100

Code code[NCODE];
int stack[NSTACK];
int stackp;
int pc; // program counter

int main()
{
  Tree *t = NULL;

  // todo -- need to generate a tree to evaluate
  // eval(t);
}

// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Local Functions
// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

int generate(int codep, Tree *t)
{
  switch (t->op) {
  case NUMBER:
    code[codep++].op = pushop;
    code[codep++].value = t->value;
    return codep;
  case VARIABLE:
    code[codep++].op = pushsymop;
    code[codep++].symbol = t->symbol;
    return codep;
  case ADD:
    codep = generate(codep, t->left);
    codep = generate(codep, t->right);
    code[codep++].op = addop;
    return codep;
  case SUBTRACT:
    codep = generate(codep, t->left);
    codep = generate(codep, t->right);
    code[codep++].op = subop;
    return codep;
  case MULTIPLY:
    codep = generate(codep, t->left);
    codep = generate(codep, t->right);
    code[codep++].op = multop;
    return codep;
  case DIVIDE:
    codep = generate(codep, t->left);
    codep = generate(codep, t->right);
    code[codep++].op = divop;
    return codep;
  }
}

int eval(Tree *t)
{
  pc = generate(0, t);
  code[pc].op = NULL;

  stackp = 0;
  pc = 0;
  while (code[pc].op != NULL)
    (*code[pc++].op)();
  
  return stack[0];
}

void pushop(void)
{
  stack[stackp++] = code[pc++].value;
}

void pushsymop(void)
{
  // todo -- add symbol support
}

void addop(void)
{
  int left, right;

  right = stack[--stackp];
  left = stack[--stackp];

  stack[stackp++] = left + right;
}

void subop(void)
{
  int left, right;

  right = stack[--stackp];
  left = stack[--stackp];

  stack[stackp++] = left - right;
}

void multop(void)
{
  int left, right;

  right = stack[--stackp];
  left = stack[--stackp];

  stack[stackp++] = left * right;
}

void divop(void)
{
  int left, right;

  right = stack[--stackp];
  left = stack[--stackp];
  
  if (right == 0)
    eprintf("divide %d by zero\n", left);
  
  stack[stackp++] = left / right;
}
