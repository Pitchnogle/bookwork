#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "util.h"

// -----------------------------------------------------------------------------
// Definitions
// -----------------------------------------------------------------------------

enum {
  NPREF = 2,     // # prefix words
  NHASH = 4093,  // size of state hash table array
  HMULT = 31,    // 
  MAXGEN = 10000 // max #words generated
};

typedef struct state_t state_t;
typedef struct suffix_t suffix_t;

// prefix + suffix list
struct state_t {
  char *prefix[NPREF]; // prefix words
  suffix_t *suffix;    // list of suffixes
  state_t *next;       // next in hash table
};

struct suffix_t {
  char *word;     // suffix
  suffix_t *next; // next in list of suffixes
};

state_t *statetab[NHASH];

char NONWORD[] = "\n";

// -----------------------------------------------------------------------------
// Function Prototypes
// -----------------------------------------------------------------------------

void build(char *prefix[NPREF], FILE *f);

unsigned int hash(char *s[NPREF]);

state_t *lookup(char *prefix[NPREF], int create);

void add(char *prefix[NPREF], char *suffix);

void add_suffix(state_t *sp, char *suffix);

void generate(int nwords);

// =============================================================================
// Main Program
// =============================================================================

int main(int argc, char *argv[])
{
  setprogname("markov");

  // Seed the random number generator
  srand(time(NULL));

  FILE *f = fopen(argv[1], "r");
  if (NULL == f) {
    eprintf("can't open %s:", argv[1]);
  }

  int i;
  int nwords = MAXGEN;
  char *prefix[NPREF];

  for (i = 0; i < NPREF; i++) {
    prefix[i] = NONWORD;
  }

  build(prefix, f);
  fclose(f);
  
  add(prefix, NONWORD);
  generate(nwords);

  return 0;
}

// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Local Functions
// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

void build(char *prefix[NPREF], FILE *f)
{
  char buf[100];
  char fmt[10];

  sprintf(fmt, "%%%lds", sizeof (buf) - 1);
  while (fscanf(f, fmt, buf) != EOF) {
    add(prefix, strdup(buf));
  }
}

unsigned int hash(char *s[NPREF])
{
  unsigned int h;
  unsigned char *p;
  int i;

  h = 0;
  for (i = 0; i < NPREF; i++) {
    for (p = (unsigned char*)s[i]; *p != '\0'; p++) {
      h = HMULT * h + *p;
    }
  }
  return h % NHASH;
}

state_t *lookup(char *prefix[NPREF], int create)
{
  int i, h;
  state_t *sp;

  h = hash(prefix);
  for (sp = statetab[h]; sp != NULL; sp = sp->next) {
    for (i = 0; i < NPREF; i++) {
      if (strcmp(prefix[i], sp->prefix[i]) != 0) {
        break;
      }
    }
    if (i == NPREF) { // found it
      return sp;
    }
  }
  if (create) {
    sp = emalloc(sizeof (state_t));
    for (i = 0; i < NPREF; i++) {
      sp->prefix[i] = prefix[i];
    }
    sp->suffix = NULL;
    sp->next = statetab[h];
    statetab[h] = sp;
  }
  return sp;
}

void add(char *prefix[NPREF], char *suffix)
{
  state_t *sp;

  sp = lookup(prefix, 1);
  add_suffix(sp, suffix);
  // Move the words down the prefix
  memmove(prefix, prefix + 1, (NPREF - 1) * sizeof (prefix[0]));
  prefix[NPREF - 1] = suffix;
}

void add_suffix(state_t *sp, char *suffix)
{
  suffix_t *s;

  s = emalloc(sizeof (suffix_t));
  s->word = suffix;
  s->next = sp->suffix;
  sp->suffix = s;
}

void generate(int nwords)
{
  state_t *sp;
  suffix_t *suffix;
  char *prefix[NPREF], *w;
  int i, nmatch;

  for (i = 0; i < NPREF; i++) {
    prefix[i] = NONWORD;
  }

  for (i = 0; i < nwords; i++) {
    sp = lookup(prefix, 0);
    nmatch = 0;
    for (suffix = sp->suffix; suffix != NULL; suffix = suffix->next) {
      if (rand() % ++nmatch == 0) { // probability = 1 / nmatch
        w = suffix->word;
      }
    }
    if (strcmp(w, NONWORD) == 0) {
      break;
    }
    printf("%s ", w);
    if (strstr(w, ".")) printf("\n");
    memmove(prefix, prefix + 1, (NPREF - 1) * sizeof (prefix[0]));
    prefix[NPREF - 1] = w;
  }
}