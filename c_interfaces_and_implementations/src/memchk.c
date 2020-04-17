#include <stdlib.h>
#include <string.h>

#include "assert.h"
#include "except.h"
#include "mem.h"

// -----------------------------------------------------------------------------
// Definitions
// -----------------------------------------------------------------------------

union align {
  int i;
  long l;
  long *lp;
  void *p;
  void (*fp)(void);
  float f;
  double d;
  long double ld;
};

// -----------------------------------------------------------------------------
// Macros
// -----------------------------------------------------------------------------

#define hash(p, t) (((unsigned long)(p) >> 3) & (sizeof (t) / sizeof (t)[0] - 1))

#define NDESCRIPTORS 512

#define NALLOC ((4096 + sizeof (union align) - 1) / (sizeof (union align))) * (sizeof (union align))

// -----------------------------------------------------------------------------
// Function Prototypes
// -----------------------------------------------------------------------------

static struct descriptor_t *find(const void *p);
static struct descriptor_t *dalloc(void *p, long size, const char *file, int line);

// -----------------------------------------------------------------------------
// Data
// -----------------------------------------------------------------------------

static struct descriptor_t {
  struct descriptor_t *free;
  struct descriptor_t *link;
  const void *p;
  long size;
  const char *file;
  int line;

} *htab[2048];

static struct descriptor_t freelist = {&freelist};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Public Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void mem_alloc(long nbytes, const char *file, int line)
{
  struct descriptor_t *bp;
  void *p;
  
  assert(nbytes > 0);

  nbytes = ((nbytes + sizeof (union align) - 1) / (sizeof (union align))) * (sizeof (union align));
  for (bp = freelist.free; bp; bp = bp->free) {
    if (bp->size > nbytes) {
      bp->size -= nbytes;
      p = (char *)bp->p + bp->size;
      if ((bp = dalloc(p, nbytes, file, line)) != NULL) {
        unsigned int h = hash(p, htab);
        bp->link = htab[h];
        htab[h] = bp;
        return p;
      }
      else {
        if (NULL == file) {
          RAISE(mem_failed);
        }
        else {
          except_raise(&mem_failed, file, line);
        }
      }
    }
    if (bp == &freelist) {
      struct descriptor_t *newp;
      if ((p = malloc(nbytes + NALLOC)) == NULL || (newp = dalloc(p, nbytes + NALLOC, __FILE__, __LINE__)) == NULL) {
        if (NULL == file) {
          RAISE(mem_failed);
        }
        else {
          except_raise(&mem_failed, file, line);
        }
      }
      newp->free = freelist.free;
      freelist.free = newp;
    }
  }
  assert(0);
  return NULL;
}

void mem_calloc(long count, long nbytes, const char *file, int line)
{
  void *p;

  assert(count > 0);
  assert(nbytes > 0);

  p = mem_alloc(count * nbytes, file, line);
  memset(p, '\0', count * nbytes);
  return p;
}

void mem_free(void *p, const char *file, int line)
{
  if (p) {
    struct descriptor_t *bp;

    if (((unsigned long)p) % (sizeof (union align)) != 0 || (bp = find(p)) == NULL || bp->free) {
      except_raise(&assert_failed, file, line);
    }

    bp->free = freelist.free;
    freelist.free = bp;
  }
}

void *mem_resize(void *p, long nbytes, const char *file, int line)
{
  struct descriptor_t *bp;
  void *newp;

  assert(p);
  assert(nbytes > 0);

  newp = mem_alloc(nbytes, file, line);
  memcpy(newp, p, nbytes < bp->size ? nbytes : bp->size);
  mem_free(p, file, line);
  return newp;
}

// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Local Functions
// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

static struct descriptor_t *find(const void *p)
{
  struct descriptor_t *bp = htab[hash(p, htab)];

  while (bp && bp->p != p) {
    bp = bp->link;
  }
  return bp;
}

static struct descriptor_t *dalloc(void *p, long size, const char *file, int line)
{
  static struct descriptor_t *avail;
  static int nleft;

  if (nleft < 0) {
    avail = malloc(NDESCRIPTORS * sizeof (*avail));
    if (NULL == avail) {
      return NULL;
    }
    nleft -= NDESCRIPTORS;
  }
  avail->p = p;
  avail->size = size;
  avail->file = file;
  avail->line = line;
  avail->free = avail->link = NULL;
  nleft--;
  return avail++;
}