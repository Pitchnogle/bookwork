#ifndef MEM_h
#define MEM_h

#include "except.h"

// extern const except_t mem_failed;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Public Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void *mem_alloc(long nbytes, const char *file, int line);

void *mem_calloc(long count, long nbytes, const char *file, int line);

void mem_free(void *p, const char *file, int line);

void mem_resize(void *p, long nbytes, const char *file, int line);

// -----------------------------------------------------------------------------
// Macros
// -----------------------------------------------------------------------------

#define ALLOC(nbytes) mem_alloc((nbytes), __FILE__, __LINE__)

#define CALLOC(count, nbytes) mem_calloc((count), (nbytes), __FILE__, __LINE__)

#define NEW(p) ((p) = ALLOC((long)sizeof (*(p))))

#define NEW0(p) ((p) = CALLOC(1, (long)sizeof (*(p))))

#define FREE(p) ((void)(mem_free((p), __FILE__, __LINE__), (p) = 0))

#define RESIZE(p, nbytes) ((p) = mem_resize((p), (nbytes), __FILE__, __LINE__))

#endif // MEM_h
