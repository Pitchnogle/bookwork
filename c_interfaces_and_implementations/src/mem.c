#include <stdlib.h>
#include <stddef.h>

#include "assert.h"
#include "except.h"
#include "mem.h"

// -----------------------------------------------------------------------------
// Data
// -----------------------------------------------------------------------------

const except_t mem_failed = {"allocation failed"};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Public Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void *mem_alloc(long nbytes, const char *file, int line)
{
  void *p;

  assert(nbytes > 0);

  p = malloc(nbytes);
  if (NULL == p) {
    if (NULL == file) {
      RAISE(mem_failed);
    }
    else {
      except_raise(&mem_failed, file, line);
    }
  }
  return p;
}

void *mem_calloc(long count, long nbytes, const char *file, int line)
{
  void *p;

  assert(count > 0);
  assert(nbytes > 0);

  p = calloc(count, nbytes);
  if (NULL == p) {
    if (NULL == file) {
      RAISE(mem_failed);
    }
    else {
      except_raise(&mem_failed, file, line);
    }
  }
  return p;
}

void mem_free(void *p, const char *file, int line)
{
  if (p) free (p);
}

void mem_resize(void *p, long nbytes, const char *file, int line)
{
  assert(p);
  assert(nbytes > 0);

  p = realloc(p, nbytes);
  if (NULL == p) {
    if (NULL == file) {
      RAISE(mem_failed);
    }
    else {
      except_raise(&mem_failed, file, line);
    }
  }
  return p;
}
