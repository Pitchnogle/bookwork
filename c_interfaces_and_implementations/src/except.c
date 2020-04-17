#include <stdlib.h>
#include <stdio.h>
#include "assert.h"
#include "except.h"

// -----------------------------------------------------------------------------
// Definitions
// -----------------------------------------------------------------------------

#define T except_t

// -----------------------------------------------------------------------------
// Data
// -----------------------------------------------------------------------------

except_frame_t *except_stack = NULL;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Public Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void except_raise(const T *e, const char *file, int line)
{
  except_frame_t *p = except_stack;

  assert(e);
  if (NULL == p) {
    fprintf(stderr, "Uncaught exception");
    if (e->reason) {
      fprintf(stderr, " %s", e->reason);
    }
    else {
      fprintf(stderr, " at 0x%p", e);
    }
    if (file && line > 0) {
      fprintf(stderr, " raised at %s:%d\n", file, line);
    }
    fprintf(stderr, "aborting...\n");
    fflush(stderr);
    abort();
  }
  p->exception = e;
  p->file = file;
  p->line = line;
  except_stack = except_stack->prev;
  longjmp(p->env, except_raised);
}