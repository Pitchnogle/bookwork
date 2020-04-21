#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#include "mem.h"
#include "assert.h"
#include "except.h"

#include "test_util.h"

// -----------------------------------------------------------------------------
// Test Functions
// -----------------------------------------------------------------------------

extern void Mem_leak(void (*apply)(void *ptr, long size, const char *file, int line, void *cl), void *cl);

// -----------------------------------------------------------------------------
// Test Functions
// -----------------------------------------------------------------------------

void test_zero_alloc();
void test_zero_calloc();
void test_negative_alloc();
void test_negative_calloc();
void test_too_big_alloc(long nbytes);
void test_too_big_calloc(long count);
void test_ok_alloc();
void test_ok_calloc();
void test_free();
void test_resize();
void test_mem_leak();

void inuse(void *ptr, long size, const char*file, int line, void *cl);

// =============================================================================
// Main Program
// =============================================================================

#define TEST_COUNT  (100)
#define TEST_TOOBIG (LONG_MAX / 2)

int main()
{
  test_zero_alloc();
  test_zero_calloc();
  test_negative_alloc();
  test_negative_calloc();
  test_too_big_alloc(TEST_TOOBIG);
  test_too_big_calloc(TEST_TOOBIG);
  test_ok_alloc();
  test_ok_calloc();
  test_free();
  test_resize();
  test_mem_leak();

  return 0;
}


// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Local Functions
// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

void test_zero_alloc()
{
  bool pass = true;
  bool caught;

  char *dummy = NULL;

  // Only a caught exception will pass test
  caught = false;
  TRY
    dummy = ALLOC(0);
  EXCEPT(Assert_Failed)
    caught = true;
  END_TRY;
  pass = pass && caught;

  print_results("Test zero ALLOC()", pass);
}

void test_zero_calloc()
{
  bool pass = true;
  bool caught;

  char *dummy = NULL;

  // Only a caught exception will pass test
  caught = false;
  TRY
    dummy = CALLOC(0, 10);
  EXCEPT(Assert_Failed)
    caught = true;
  END_TRY;
  pass = pass && caught;

  // Only a caught exception will pass test
  caught = false;
  TRY
    dummy = CALLOC(10, 0);
  EXCEPT(Assert_Failed)
    caught = true;
  END_TRY;
  pass = pass && caught;

  print_results("Test zero CALLOC()", pass);
}

void test_negative_alloc()
{
  bool pass = true;
  bool caught;

  char *dummy = NULL;

  // Only a caught exception will pass test
  caught = false;
  TRY
    dummy = ALLOC(-1);
  EXCEPT(Assert_Failed)
    caught = true;
  END_TRY;
  pass = pass && caught;

  print_results("Test negative ALLOC()", pass);
}

void test_negative_calloc()
{
  bool pass = true;
  bool caught;

  int *dummy = NULL;

  // Only a caught exception will pass test
  caught = false;
  TRY
    dummy = CALLOC(-1, sizeof (*dummy));
  EXCEPT(Assert_Failed)
    caught = true;
  END_TRY;
  pass = pass && caught;

  // Only a caught exception will pass test
  caught = false;
  TRY
    dummy = CALLOC(10, -1);
  EXCEPT(Assert_Failed)
    caught = true;
  END_TRY;
  pass = pass && caught;

  print_results("Test negative CALLOC()", pass);
}

void test_too_big_alloc(long nbytes)
{
  // This will attempt to allocate more memory than available
  bool pass = true;
  bool caught;

  char *dummy = NULL;

  // Only a caught exception will pass test
  caught = false;
  TRY
    dummy = ALLOC(nbytes);
  EXCEPT(Mem_Failed)
    caught = true;
  END_TRY;
  pass = pass && caught;

  if (dummy != NULL) 
    FREE(dummy);

  print_results("Test too big ALLOC()", pass);
}

void test_too_big_calloc(long count)
{
  // This will attempt to allocate more memory than available
  bool pass = true;
  bool caught;

  char *dummy = NULL;

  // Only a caught exception will pass test
  caught = false;
  TRY
    dummy = CALLOC(count, 1);
  EXCEPT(Mem_Failed)
    caught = true;
  END_TRY;
  pass = pass && caught;

  if (dummy != NULL) 
    FREE(dummy);

  print_results("Test too big CALLOC()", pass);
}

void test_ok_alloc()
{
  bool pass = true;

  char *x = NULL;

  TRY
    x = ALLOC(TEST_COUNT * sizeof (char));
  EXCEPT(Mem_Failed)
    pass = false;
  END_TRY;

  // Make sure we can access the bytes allocated
  int i;
  for (i = 0; i < TEST_COUNT; i++) {
    x[i] = i;
  }

  if (NULL == x) 
    pass = false;
  else
    FREE(x);

  print_results("Test ok ALLOC()", pass);
}

void test_ok_calloc()
{
  bool pass = true;

  int *x = NULL;

  TRY
    x = CALLOC(TEST_COUNT, sizeof (int));
  EXCEPT(Mem_Failed)
    pass = false;
  END_TRY;

  // Make sure we can access the bytes allocated
  int i;
  for (i = 0; i < TEST_COUNT; i++) {
    x[i] = i;
  }

  if (NULL == x) 
    pass = false;
  else
    FREE(x);

  print_results("Test ok CALLOC()", pass);
}

void test_free()
{
  bool pass = true;
  double *x = NULL;

  TRY
    x = ALLOC(TEST_COUNT * sizeof (double));
  EXCEPT(Mem_Failed)
    pass = false;
  END_TRY;

  FREE(x);

  if (NULL != x) 
    pass = false;

  print_results("Test FREE()", pass);

}

void test_resize()
{
  bool pass = true;
  bool caught;

  int *x = NULL;
  int *y = NULL;

  // Test null resize
  caught = false;
  TRY
    y = RESIZE(x, TEST_COUNT);
  EXCEPT(Assert_Failed)
    caught = true;
  END_TRY;
  pass = pass && caught;
  pass = pass && x == NULL && y == NULL;

  x = ALLOC(TEST_COUNT * sizeof (int));

  // Test negative size
  caught = false;
  TRY
    y = RESIZE(x, -1);
  EXCEPT(Assert_Failed)
    caught = true;
  END_TRY;
  pass = pass && caught;
  pass = pass && y == NULL;

  // Test actual resize
  TRY
    y = RESIZE(x, 2 * TEST_COUNT * sizeof (int));
  EXCEPT(Mem_Failed)
    pass = false;
  END_TRY;

  if (NULL != y) {
    x = y;
    y = NULL;
  }

  FREE(x);

  print_results("Test RESIZE()", pass);
}

void test_mem_leak()
{
  bool pass = true;

  float *x = NULL;

  TRY
    x = ALLOC(TEST_COUNT * sizeof (*x));
  EXCEPT(Mem_Failed)
    pass = false;
  END_TRY;
 
  printf("Test mem leak: (there should be one leak)\n");
  Mem_leak(inuse, stdout);

  FREE(x);
  printf("Test mem leak: (nothing should print after)\n");
  Mem_leak(inuse, stdout);
}

void inuse(void *ptr, long size, const char *file, int line, void *cl)
{
  FILE *fout = cl;

  fprintf(fout, "** memory in use at %p\n", ptr);
  fprintf(fout, "This block is %ld bytes long and was allocated from %s:%d\n", size, file, line);
}