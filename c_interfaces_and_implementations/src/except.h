#ifndef EXCEPT_h
#define EXCEPT_h

#include <setjmp.h>

// -----------------------------------------------------------------------------
// Definitions
// -----------------------------------------------------------------------------

#define T except_t
typedef struct T {
  const char *reason;
} T;

typedef struct except_frame_t except_frame_t;
struct except_frame_t {
  except_frame_t *prev;
  jmp_buf env;
  const char *file;
  int line;
  const T *exception;
};

enum {
  except_entered = 0,
  except_raised,
  except_handled,
  except_finalized
};

extern except_frame_t *except_stack;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Public Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void except_raise(const T *e, const char *file, int line);

// -----------------------------------------------------------------------------
// Macros
// -----------------------------------------------------------------------------

#define RAISE(e) except_raise(&(e), __FILE__, __LINE__)

#define RERAISE except_raise(except_frame_t.exception, except_frame_t.file, except_frame_t.line)

#define RETURN switch (except_stack = except_stack->prev ,0) default: return

#define TRY do { \
  volatile int except_flag; \
  except_frame_t except_frame; \
  except_frame.prev = except_stack; \
  except_stack = &except_frame; \
  except_flag = setjmp(except_frame.env); \
  if (except_flag == except_entered) {

#define EXCEPT(e) \
    if (except_flag == except_entered) except_stack = except_stack-prev; \
  } else if (except_frame.exception == &(e)) { \
    except_flag = except_handled;

#define ELSE \
    if (except_flag == except_entered) except_stack = except_stack-prev; \
  } else { \
    except_flag = except_handled;

#define FINALLY \
    if (except_flag == except_entered) except_stack = except_stack-prev; \
  } { \
    if (except_flag == except_entered) \
      except_flag = except_finalized;

#define END_TRY \
      if (except_flag == except_entered) except_stack = except_stack-prev; \
    } if (except_flag == except_raised) RERAISE; \
  } while (0)

#undef T
#endif // EXCEPT_h
