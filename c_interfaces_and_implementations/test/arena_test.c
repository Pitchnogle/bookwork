#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#include "arena.h"
#include "assert.h"
#include "except.h"

#include "test_util.h"

// -----------------------------------------------------------------------------
// Test Functions
// -----------------------------------------------------------------------------

void test_new_arena();
void test_dispose_null();
void test_dispose_empty();
void test_alloc_null();
void test_alloc_negative();
void test_calloc_negative();
void test_alloc_empty();
void test_calloc_empty();

// =============================================================================
// Main Program
// =============================================================================

#define TEST_COUNT 1000

int main()
{
  test_new_arena();
  test_dispose_null();
  test_dispose_empty();
  test_alloc_null();
  test_alloc_negative();
  test_calloc_negative();
  test_alloc_empty();
  test_calloc_empty();

  return 0;
}


// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Local Functions
// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

void test_new_arena()
{
  bool pass = true;

  Arena_T arena = NULL;

  TRY
    arena = Arena_new();
  EXCEPT(Arena_NewFailed)
    pass = false;
  END_TRY;

  print_results("Test new arena", pass);
}

void test_dispose_null()
{
  bool pass = false;

  Arena_T arena = NULL;

  TRY
    Arena_dispose(&arena);
  EXCEPT(Assert_Failed)
    pass = true;
  END_TRY;

  print_results("Test dispose null", pass);
}

void test_dispose_empty()
{
  bool pass = true;

  Arena_T arena = NULL;

  TRY
    arena = Arena_new();
  EXCEPT(Arena_NewFailed)
    pass = false;
  END_TRY;

  TRY
    Arena_dispose(&arena);
  EXCEPT(Assert_Failed)
    pass = false;
  END_TRY;

  print_results("Test dispose empty", pass);
}

void test_alloc_null()
{
  bool pass = false;

  Arena_T arena = NULL;

  TRY
    Arena_alloc(arena, TEST_COUNT, __FILE__, __LINE__);
  EXCEPT(Assert_Failed)
    pass = true;
  END_TRY;

  print_results("Test alloc null", pass);
}

void test_alloc_negative()
{
  bool pass = false;

  Arena_T arena = NULL;

  TRY
    Arena_alloc(arena, -1, __FILE__, __LINE__);
  EXCEPT(Assert_Failed)
    pass = true;
  END_TRY;

  print_results("Test alloc negative", pass);
}

void test_calloc_negative()
{
  bool pass = false;

  Arena_T arena = NULL;

  TRY
    Arena_calloc(arena, -1, TEST_COUNT, __FILE__, __LINE__);
  EXCEPT(Assert_Failed)
    pass = true;
  END_TRY;

  print_results("Test calloc negative", pass);
}


void test_alloc_empty()
{
  bool pass = true;

  Arena_T arena = NULL;
  int *x = NULL;

  TRY
    arena = Arena_new();
  EXCEPT(Arena_NewFailed)
    pass = false;
  END_TRY;

  TRY
    x = Arena_alloc(arena, TEST_COUNT, __FILE__, __LINE__);
  EXCEPT(Assert_Failed)
    pass = false;
  EXCEPT(Arena_Failed)
    pass = false;
  END_TRY;

  TRY
    Arena_dispose(&arena);
  EXCEPT(Assert_Failed)
    pass = false;
  END_TRY;

  print_results("Test alloc empty", pass);
}

void test_calloc_empty()
{
  bool pass = true;

  Arena_T arena = NULL;
  int *x = NULL;

  TRY
    arena = Arena_new();
  EXCEPT(Arena_NewFailed)
    pass = false;
  END_TRY;

  TRY
    x = Arena_calloc(arena, TEST_COUNT, TEST_COUNT, __FILE__, __LINE__);
  EXCEPT(Assert_Failed)
    pass = false;
  EXCEPT(Arena_Failed)
    pass = false;
  END_TRY;

  TRY
    Arena_dispose(&arena);
  EXCEPT(Assert_Failed)
    pass = false;
  END_TRY;

  print_results("Test calloc empty", pass);
}
