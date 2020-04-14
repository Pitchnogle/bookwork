#ifndef STACK_h
#define STACK_h

// -----------------------------------------------------------------------------
// Definitions
// -----------------------------------------------------------------------------

#define T stack_t
typedef struct T *T;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Public Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

T     stack_new(void);
int   stack_empty(T stack);
void  stack_push(T stack, void *x);
void* stack_pop(T stack);
void  stack_free(T *stack);

#undef T
#endif // STACK_h
