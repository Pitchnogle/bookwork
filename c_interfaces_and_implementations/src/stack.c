#include <stddef.h>

#include "assert.h"
#include "mem.h"
#include "stack.h"

// -----------------------------------------------------------------------------
// Definitions
// -----------------------------------------------------------------------------

struct T {
  int count;

  struct elem {
    void *x;
    struct elem *link;
  } *head;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Public Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

T stack_new()
{
  T stack;

  NEW(stack);
  stack->count = 0;
  stack->head = NULL;

  return stack;
}

int stack_empty(T stack)
{
  assert(stack);

  return stack->count == 0;
}

void stack_push(T stack, void *x)
{
  struct elem *t;
  
  assert(stack);

  NEW(t);
  t->x = x;
  t->link = stack->head;
  stack->head = t;
  stack->count++;
}

void* stack_pop(T stack)
{
  void *x;
  struct elem *t;

  assert(stack);
  assert(stack->count > 0);

  t = stack->head;
  stack->head = t->link;
  stack->count--;

  x = t->x;
  FREE(t);

  return x;
}

void stack_free(T *stack)
{
  struct elem *t, *u;

  assert(stack && *stack);

  for (t = (*stack)->head; t; t = u) {
    u = t->link;
    FREE(t);
  }
  FREE(*stack);
}
