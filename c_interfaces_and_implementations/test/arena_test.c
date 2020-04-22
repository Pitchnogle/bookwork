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
void test_alloc();

// =============================================================================
// Main Program
// =============================================================================

#define TEST_COUNT   (1000)
#define ALLOC_SIZES  (8)
#define TOTAL_ALLOCS (1000)

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
  test_alloc();

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

void test_alloc()
{
  bool pass = true;

  Arena_T arena = NULL;

  TRY
    arena = Arena_new();
  EXCEPT(Arena_NewFailed)
    pass = false;
  END_TRY;

  int alloc_size[ALLOC_SIZES] = {
    1024, 2048, 512, 8096, 1024, 2048, 512, 512
  };

  int *x[TOTAL_ALLOCS] = {0};

  int i;
  for (i = 0; i < TOTAL_ALLOCS; i++) {
    TRY
      x[i] = Arena_alloc(arena, alloc_size[i % ALLOC_SIZES], __FILE__, __LINE__);
    EXCEPT(Assert_Failed)
      pass = false;
    EXCEPT(Arena_Failed)
      pass = false;
    END_TRY;
  }

  TRY
    Arena_dispose(&arena);
  EXCEPT(Assert_Failed)
    pass = false;
  END_TRY;

  print_results("Test alloc", pass);
}
