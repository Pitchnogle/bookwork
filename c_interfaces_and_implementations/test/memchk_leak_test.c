#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#include "mem.h"
#include "assert.h"
#include "except.h"

#include "test_util.h"

// -----------------------------------------------------------------------------
// External Functions
// -----------------------------------------------------------------------------

extern void Mem_leak(void (*apply)(void *ptr, long size, const char *file, int line, void *cl), void *cl);
extern int Mem_num_leaks();

// -----------------------------------------------------------------------------
// Test Functions
// -----------------------------------------------------------------------------

void inuse(void *ptr, long size, const char*file, int line, void *cl);

// =============================================================================
// Main Program
// =============================================================================

#define TOTAL_ALLOCS 2049 // > TOTAL_BUCKETS in memchk.c
#define ARRAY_LEN    100

int main()
{
  // This program is intentionally creating memory leaks to see if we can count
  // them. Since the memchk is using a hash table internally, to ensure we test
  // each bucket, we make sure to allocate greater than the total buckets. It's
  // possible that some buckets are NULL, but we are guaranteed that one bucket
  // has at least of length of 2.

  // Our goal here is to just count the number of memory leaks, which should 
  // match the number of calls to ALLOC

  int i;
  for (i = 0; i < TOTAL_ALLOCS; i++) {
    TRY
      int *x = ALLOC(ARRAY_LEN * sizeof((*x)));
    EXCEPT(Mem_Failed)
      // do nothing
    END_TRY;
  }

  Mem_leak(inuse, stdout);
  print_results("Test mem leak()", TOTAL_ALLOCS == Mem_num_leaks());

  return 0;
}

// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Local Functions
// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

void inuse(void *ptr, long size, const char *file, int line, void *cl)
{
  FILE *fout = cl;

  // To see the leak info uncomment these lines...
  // fprintf(fout, "** memory in use at %p\n", ptr);
  // fprintf(fout, "This block is %ld bytes long and was allocated from %s:%d\n", size, file, line);
}