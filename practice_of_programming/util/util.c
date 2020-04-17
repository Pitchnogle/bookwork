#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>

#include "util.h"

// +-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+-+
// Variables
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

static char *name = NULL; // program name for messages

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Utility Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void eprintf(char *fmt, ...)
{
  va_list args;

  fflush(stdout);
  if (progname() != NULL)
    fprintf(stderr, "%s: ", progname());
  
  va_start(args, fmt);
  vfprintf(stderr, fmt, args);
  va_end(args);

  if (fmt[0] != '\0' && fmt[strlen(fmt) - 1] == ':')
    fprintf(stderr, " %s", strerror(errno));

  fprintf(stderr, "\n");
  exit(2); // conventional value for failed execution
}

void weprintf(char *fmt, ...)
{
  va_list args;

  fflush(stdout);
  if (progname() != NULL)
    fprintf(stderr, "%s: ", progname());
  
  va_start(args, fmt);
  vfprintf(stderr, fmt, args);
  va_end(args);

  if (fmt[0] != '\0' && fmt[strlen(fmt) - 1] == ':')
    fprintf(stderr, " %s", strerror(errno));

  fprintf(stderr, "\n");
}

char *estrdup(char *s)
{
  char *t;

  t = malloc(strlen(s) + 1);
  if (NULL == t)
    eprintf("estrdup(\"%.20s\") failed:", s);
  
  strcpy(t, s);
  return t;
}

void *emalloc(size_t n)
{
  void *p;

  p = malloc(n);
  if (NULL == p)
    eprintf("malloc of %u bytes failed:", n);
  
  return p;
}

void *erealloc(void *p, size_t n)
{
  void *newp;

  newp = realloc(p, n);
  if (NULL == newp)
    eprintf("remalloc of %u bytes failed:", n);
  
  p = newp;
  return p;
}

char *progname(void)
{
  return name;
}

void setprogname(char *s)
{
  name = estrdup(s);
}

