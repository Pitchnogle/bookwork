#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack.h"
#include "mem.h"
#include "assert.h"
#include "except.h"

#include "test_util.h"

// -----------------------------------------------------------------------------
// Test Functions
// -----------------------------------------------------------------------------

void test_null_stack();
void test_empty_stack();
void test_pop_empty_stack();
void test_push_pop_stack(int n);
void test_free_non_empty_stack(int n);

// =============================================================================
// Main Program
// =============================================================================

#define NUM_PUSHES 10

int main()
{
  test_null_stack();
  test_empty_stack();
  test_pop_empty_stack();
  test_push_pop_stack(NUM_PUSHES);
  test_free_non_empty_stack(NUM_PUSHES);

  return 0;
}

// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Local Functions
// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

void test_null_stack()
{
  bool pass = true;
  bool caught;

  Stack_T stack = NULL;

  // Only a caught exception will pass test
  caught = false;
  TRY
    Stack_empty(stack);
  EXCEPT(Assert_Failed)
    caught = true;
  END_TRY;
  pass = pass && caught;

  int dummy = 1;

  // Only a caught exception will pass test
  caught = false;
  TRY
    Stack_push(stack, &dummy);
  EXCEPT(Assert_Failed)
    caught = true;
  END_TRY;
  pass = pass && caught;

  // Only a caught exception will pass test
  caught = false;
  TRY
    Stack_pop(stack);
  EXCEPT(Assert_Failed)
    caught = true;
  END_TRY;
  pass = pass && caught;

  // Only a caught exception will pass test
  caught = false;
  TRY
    Stack_free(&stack);
  EXCEPT(Assert_Failed)
    caught = true;
  END_TRY;
  pass = pass && caught;

  print_results("Test NULL stack()", pass);
}

void test_empty_stack()
{
  bool pass = true;

  Stack_T stack = Stack_new();
  pass = pass && stack != NULL;

  pass = pass && Stack_empty(stack);

  Stack_free(&stack);

  print_results("Test empty stack()", pass);
}

void test_pop_empty_stack()
{
  bool pass = false;

  Stack_T stack = Stack_new();

  TRY
    Stack_pop(stack);
  EXCEPT(Assert_Failed)
    pass = true;
  END_TRY;

  Stack_free(&stack);

  print_results("Test pop empty stack()", pass);
}

void test_push_pop_stack(int n)
{
  bool pass = true;

  Stack_T stack = Stack_new();
  pass = pass && stack != NULL;
  pass = pass && Stack_empty(stack);

  // Allocate memory for source data
  int *x = malloc(n * sizeof ((*x)));
  if (NULL == x) {
    pass = false;
    goto exit;
  }

  // Push data onto stack
  int i;
  for (i = 0; i < n; i++) {
    x[i] = i + 1;
    Stack_push(stack, &x[i]);
  }
  pass = pass && !Stack_empty(stack);

  // Pop data off stack and compare
  int j;
  for (i = 0, j = n; i < n; i++, j--) {
    int *v = Stack_pop(stack);
    pass = pass && *v == j;
  }

  // Fully popped stack should be empty
  pass = pass && Stack_empty(stack);

exit:
  if (NULL != x) free (x);

  Stack_free(&stack);

  print_results("Test push/pop stack()", pass);
}

void test_free_non_empty_stack(int n)
{
  bool pass = true;

  Stack_T stack = Stack_new();
  pass = pass && stack != NULL;
  pass = pass && Stack_empty(stack);

  int i;
  for (i = 0; i < n; i++) {
    int *v = malloc(sizeof (v));
    if (NULL == v) {
      pass = false;
      goto exit;
    }
    *v = i;
    Stack_push(stack, v);
    free (v);
  }
  pass = pass && !Stack_empty(stack);

exit:

  Stack_free(&stack);
  pass = pass && stack == NULL;

  print_results("Test free non-empty stack()", pass);
}
