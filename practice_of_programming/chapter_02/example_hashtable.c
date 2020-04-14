/*
This program demonstrates hashtable of nameval_t

The program works in a similar way to the array versions, but with a hash table

Example output:
Looking for entry in the hash table:
The HTML character code for "&frac12;" is 0xBD

Looking for entry not in the hash table:
The HTML character code for "&dummy;" was not found!

Looking for another entry in the hash table
The HTML character code for "&cent;" is 0xA2
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// -----------------------------------------------------------------------------
// Definitions
// -----------------------------------------------------------------------------

#define NHASH 1031

typedef struct nameval_t nameval_t;

struct nameval_t {
  char *name;
  int value;
  nameval_t *next;
};

nameval_t *symtab[NHASH];

enum {
  HASH_MULT = 31
};

// -----------------------------------------------------------------------------
// Function Prototypes
// -----------------------------------------------------------------------------

void build(FILE *f);

unsigned int hash(char *str);

nameval_t *lookup(char *name, int create, int value);

// =============================================================================
// Main Program
// =============================================================================

int main()
{
  // Clear out the hash table
  int i;
  for (i = 0; i < NHASH; i++) {
    symtab[i] = NULL;
  }

  // We read the html character table from a file
  const char *fname = "html_chars.txt";
  FILE *f = fopen(fname, "r");
  if (NULL == f) {
    printf("Unable to open %s\n", fname);
    exit (1);
  }
  build(f);
  fclose(f);

  // Let's look for an entry
  printf("Looking for entry in the hash table:\n");
  char *s = "&frac12;";
  nameval_t *item = lookup(s, 0, i);
  if (NULL != item) {
    printf("The HTML character code for \"%s\" is 0x%X\n", s, item->value);
  }
  else {
    printf("The HTML character code for \"%s\" was not found!\n", s);
  }

  // Let's look for something not in the hash table
  printf("\nLooking for entry not in the hash table:\n");
  s = "&dummy;";
  item = lookup(s, 0, i);
  if (NULL != item) {
    printf("The HTML character code for \"%s\" is 0x%X\n", s, item->value);
  }
  else {
    printf("The HTML character code for \"%s\" was not found!\n", s);
  }

  // Let's look for another entry
  printf("\nLooking for another entry in the hash table\n");
  s = "&cent;";
  item = lookup(s, 0, i);
  if (NULL != item) {
    printf("The HTML character code for \"%s\" is 0x%X\n", s, item->value);
  }
  else {
    printf("The HTML character code for \"%s\" was not found!\n", s);
  }

  return 0;
}

// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Local Functions
// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

void build(FILE *f)
{
  char buf[80];
  char fmt[40];
  int value;

  // This essentially builds the string: "%79s %x"
  sprintf(fmt, "%%%lds %%x\n", sizeof(buf) - 1);
  while (fscanf(f, fmt, buf, &value) != EOF) {
    lookup(buf, 1, value);
  }
}

unsigned int hash(char *str)
{
  unsigned int h;
  unsigned char *p;

  h = 0;
  for (p = (unsigned char*)str; *p != '\0'; p++) {
    h = HASH_MULT * h + *p;
  }
  return h % NHASH;
}

nameval_t *lookup(char *name, int create, int value)
{
  int h;
  nameval_t *sym;

  h = hash(name);
  for (sym = symtab[h]; sym != NULL; sym = sym->next) {
    if (strcmp(name, sym->name) == 0) {
      return sym;
    }
  }
  if (create) {
    sym = malloc(sizeof (nameval_t));
    if (NULL == sym) {
      exit(1);
    }
    sym->name = strdup(name);
    sym->value = value;
    sym->next = symtab[h];
    symtab[h] = sym;
  }
  return sym;
}
