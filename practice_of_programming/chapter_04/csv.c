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

typedef struct csv_t {
  char *line;     // Input characters
  char *sline;    // Line copy used by split
  int maxline;    // size of line[] and sline[]
  char **field;   // Field pointers
  int maxfield;   // size of field[]
  int nfield;     // #fields in field[]
} csv_t;

// -----------------------------------------------------------------------------
// Function Prototypes
// -----------------------------------------------------------------------------

static int end_of_line(FILE *fin, int c);
static int split(csv csv);
static char *advquoted(char *p);

// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// Variables
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

static const char fieldsep[] = ","; // Field separator chars

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Public Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

csv csv_new()
{
  csv csv = malloc (sizeof (csv_t));
  if (NULL != csv) {
    csv->line = NULL;
    csv->sline = NULL;
    csv->maxline = 0;
    csv->field = NULL;
    csv->maxfield = 0;
    csv->nfield = 0;
  }
  return csv;
}

void csv_reset(csv csv)
{
  if (NULL == csv) return;  
  
  free (csv->line);
  free (csv->sline);
  free (csv->field);
  csv->line = NULL;
  csv->sline = NULL;
  csv->field = NULL;
  csv->maxline = csv->maxfield = csv->nfield = 0;
}

char *csv_getline(csv csv, FILE *fin)
{
  int i, c;
  char *newl, *news;

  if (NULL == csv->line) {
    csv->maxline = csv->maxfield = 1;
    csv->line = malloc(csv->maxline);
    csv->sline = malloc(csv->maxline);
    csv->field = malloc(csv->maxfield * sizeof (csv->field[0]));
    if (NULL == csv->line || NULL == csv->sline || NULL == csv->field) {
      csv_reset(csv);
      return NULL; // out-of-memory
    }
  }
  for (i = 0; (c = getc(fin)) != EOF && !end_of_line(fin, c); i++) {
    if (i >= csv->maxline - 1) { // grow line
      csv->maxline *= 2;
      newl = realloc(csv->line, csv->maxline);
      news = realloc(csv->line, csv->maxline);
      if (NULL == newl || NULL == news) {
        csv_reset(csv);
        return NULL; // out-of-memory
      }
      csv->line = newl;
      csv->sline = news;
    }
    csv->line[i] = c;
  }
  csv->line[i] = '\0';
  if (split(csv) == NOMEM) {
    csv_reset(csv);
    return NULL; // out-of-memory
  }
  return (c == EOF && i == 0) ? NULL : csv->line;
}

char *csv_field(csv csv, int n)
{
  if (n < 0 || csv == NULL || n >= csv->nfield) {
    return NULL;
  }
  return csv->field[n];
}

int csv_nfield(csv csv)
{
  if (csv == NULL) return -1;

  return csv->nfield;
}

// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Local Functions
// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

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

static int split(csv csv)
{
  char *p, **newf;
  char *sepp; // pointer to temporary separator character
  int sepc;   // temporary separator character

  csv->nfield = 0;
  if (csv->line[0] == '\0') {
    return 0;
  }
  strcpy(csv->sline, csv->line);
  p = csv->sline;

  do {
    if (csv->nfield >= csv->maxfield) {
      csv->maxfield *= 2;
      newf = realloc(csv->field, csv->maxfield * sizeof (csv->field[0]));
      if (NULL == newf) {
        return NOMEM;
      }
      csv->field = newf;
    }
    if (*p == '"') {
      sepp = advquoted(++p);
    }
    else {
      sepp = p + strcspn(p, fieldsep);
    }
    sepc = sepp[0];
    sepp[0] = '\0';
    csv->field[csv->nfield++] = p;
    p = sepp + 1;
  } while (sepc == ',');

  return csv->nfield;
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
