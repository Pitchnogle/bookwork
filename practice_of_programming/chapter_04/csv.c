#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "csv.h"

// -----------------------------------------------------------------------------
// Definitions
// -----------------------------------------------------------------------------

enum {
  NOMEM = 2 // out-of-memory signal
};

// -----------------------------------------------------------------------------
// Function Prototypes
// -----------------------------------------------------------------------------

static void reset();
static int end_of_line(FILE *fin, int c);
static int split();
static char *advquoted(char *p);

// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// Variables
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

static char *line = NULL;     // Input characters
static char *sline = NULL;    // Line copy used by split
static int maxline = 0;       // size of line[] and sline[]
static char **field = NULL;   // Field pointers
static int maxfield = 0;      // size of field[]
static int nfield = 0;        // #fields in field[]

static char fieldsep[] = ","; // Field separator chars

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Public Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

char *csv_getline(FILE *fin)
{
  int i, c;
  char *newl, *news;

  if (NULL == line) {
    maxline = maxfield = 1;
    line = malloc(maxline);
    sline = malloc(maxline);
    field = malloc(maxfield * sizeof (field[0]));
    if (NULL == line || NULL == sline || NULL == field) {
      reset();
      return NULL; // out-of-memory
    }
  }
  for (i = 0; (c = getc(fin)) != EOF && !end_of_line(fin, c); i++) {
    if (i >= maxline - 1) { // grow line
      maxline *= 2;
      newl = realloc(line, maxline);
      news = realloc(line, maxline);
      if (NULL == newl || NULL == news) {
        reset();
        return NULL; // out-of-memory
      }
      line = newl;
      sline = news;
    }
    line[i] = c;
  }
  line[i] = '\0';
  if (split() == NOMEM) {

  }
  return (c == EOF && i == 0) ? NULL : line;
}

char *csv_field(int n)
{
  if (n < 0 || n >= nfield) {
    return NULL;
  }
  return field[n];
}

int csv_nfield(void)
{
  return nfield;
}

// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
//
// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

// Set variables back to starting values
static void reset()
{
  free (line);
  free (sline);
  free (field);
  line = NULL;
  sline = NULL;
  field = NULL;
  maxline = maxfield = nfield = 0;
}

// Check for and consume \r, \n, \r\n, or EOF
static int end_of_line(FILE *fin, int c)
{
  int eol = (c == '\r' || c == '\n');
  
  if (c == '\r') {
    c = getc(fin);
    if (c != '\n' && c != EOF) {
      ungetc(c, fin); // read too far; put c back
    }
  }
  return eol;
}

static int split()
{
  char *p, **newf;
  char *sepp; // pointer to temporary separator character
  int sepc;   // temporary separator character

  nfield = 0;
  if (line[0] == '\0') {
    return 0;
  }
  strcpy(sline, line);
  p = sline;

  do {
    if (nfield >= maxfield) {
      maxfield *= 2;
      newf = realloc(field, maxfield * sizeof (field[0]));
      if (NULL == newf) {
        return NOMEM;
      }
      field = newf;
    }
    if (*p == '"') {
      sepp = advquoted(++p);
    }
    else {
      sepp = p + strcspn(p, fieldsep);
    }
    sepc = sepp[0];
    sepp[0] = '\0';
    field[nfield++] = p;
    p = sepp + 1;
  } while (sepc == ',');

  return nfield;
}

// Quouted-field: return pointer to next separator
static char *advquoted(char *p)
{
  int i, j;

  for (i = j = 0; p[j] != '\0'; i++, j++) {
    if (p[j] == '"' && p[++j] != '"') {
      // Copy up to next separator or \0
      int k = strcspn(p + j, fieldsep);
      memmove(p + i, p + j, k);
      i += k;
      j += k;
      break;
    }
    p[i] = p[j];
  }
  p[i] = '\0';
  return p + j;
}
