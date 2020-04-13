/*
This program demonstrates binary search of growable array

This starts with the example_array1.c example, but instead of using the 
predefined array in html_chars.h, we can add and delete entries from it
as we go. The html_chars.txt file is used to source the initial table.

Example output:
The nameval table has 100 entries

Looking for entry in the table:
The HTML character code for "&frac12;" is 0xBD

Looking for entry not in the table:
The HTML character code for "&frac14;" is 0xBC

Looking for another entry in the table
The HTML character code for "&cent;" is 0xA2
The HTML character code entry "&cent;" was deleted
The nameval table now has 99 entries

Looking for the just deleted entry:
The HTML character code for "&cent;" was not found!

Attempt to delete an entry not in the table:
The HTML character code for "&cent;" was not found in table!
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// -----------------------------------------------------------------------------
// Data Structures
// -----------------------------------------------------------------------------

typedef struct nameval_t nameval_t;

struct nameval_t {
  char *name;
  int   value;
};

struct nvtab_t {
  int nval;           // current # of values in array
  int max;            // allocated # of values
  nameval_t *nameval; // array of name-value pairs
} nvtab;

enum {
  NVINIT = 1,
  NVGROW = 2
};

// -----------------------------------------------------------------------------
// Function Prototypes
// -----------------------------------------------------------------------------

void build(FILE *f);

int scmp(const void *p1, const void *p2);
int nvcmp(const void *p1, const void *p2);

int lookup(char *name, nameval_t tab[], int ntab);

int addname(nameval_t newname);
int delname(char *name);

// =============================================================================
// Main Program
// =============================================================================

int main()
{
  nvtab.nameval = NULL;

  // In this version, we read the html character table from a file
  const char *fname = "html_chars.txt";
  FILE *f = fopen(fname, "r");
  if (NULL == f) {
    printf("Unable to open %s\n", fname);
    exit (1);
  }
  build(f);
  fclose(f);

  printf("The nameval table has %d entries\n", nvtab.nval);

  // The lookup() function using a binary search which requires the html 
  // character table to be sorted!
  qsort(nvtab.nameval, nvtab.nval, sizeof (nameval_t), scmp);

  // Let's look for an entry
  printf("\nLooking for entry in the table:\n");
  char *s = "&frac12;";
  int i = lookup(s, nvtab.nameval, nvtab.nval);
  if (i != -1) {
    int v = nvtab.nameval[i].value;
    printf("The HTML character code for \"%s\" is 0x%X\n", s, v);
  }
  else {
    printf("The HTML character code for \"%s\" was not found!\n", s);
  }

  // Let's look for something not in the table
  printf("\nLooking for entry not in the table:\n");
  s = "&frac14;";
  i = lookup(s, nvtab.nameval, nvtab.nval);
  if (i != -1) {
    int v = nvtab.nameval[i].value;
    printf("The HTML character code for \"%s\" is 0x%X\n", s, v);
  }
  else {
    printf("The HTML character code for \"%s\" was not found!\n", s);
  }

  // Let's look for another entry
  printf("\nLooking for another entry in the table\n");
  s = "&cent;";
  i = lookup(s, nvtab.nameval, nvtab.nval);
  if (i != -1) {
    int v = nvtab.nameval[i].value;
    printf("The HTML character code for \"%s\" is 0x%X\n", s, v);
  }
  else {
    printf("The HTML character code for \"%s\" was not found!\n", s);
  }

  // Let's delete that entry (it should be succesful)
  // printf("\nAttempt to delete an entry:\n");
  if (!delname(s)) {
    printf("The HTML character code for \"%s\" was not found in table!\n", s);
  }
  else {
    printf("The HTML character code entry \"%s\" was deleted\n", s);
  }
  printf("The nameval table now has %d entries\n", nvtab.nval);

  // Let's search again for the deleted entry (should not be found)
  printf("\nLooking for the just deleted entry:\n");
  i = lookup(s, nvtab.nameval, nvtab.nval);
  if (i != -1) {
    int v = nvtab.nameval[i].value;
    printf("The HTML character code for \"%s\" is 0x%X\n", s, v);
  }
  else {
    printf("The HTML character code for \"%s\" was not found!\n", s);
  }

  // Let's attempt to delete non-existent entry
  printf("\nAttempt to delete an entry not in the table:\n");
  if (!delname(s)) {
    printf("The HTML character code for \"%s\" was not found in table!\n", s);
  }
  else {
    printf("The HTML character code entry \"%s\" was deleted\n", s);
  }

  // Free the memory used by the nameval table
  for (i = 0; i < nvtab.nval; i++) {
    free (nvtab.nameval[i].name);
  }
  free (nvtab.nameval);
  
  return 0;
}

// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Local Functions
// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

void build(FILE *f)
{
  char buf[80];
  char fmt[40];
  nameval_t nv;

  // This essentially builds the string: "%79s %x"
  sprintf(fmt, "%%%lds %%x\n", sizeof(buf) - 1);
  while (fscanf(f, fmt, buf, &nv.value) != EOF) {
    nv.name = strdup(buf);
    addname(nv);
  }
}

int scmp(const void *p1, const void *p2)
{
  char *v1, *v2;
  v1 = *(char**)p1;
  v2 = *(char**)p2;
  return strcmp(v1, v2);
}

int nvcmp(const void *p1, const void *p2)
{
  const nameval_t *n1, *n2;
  n1 = (nameval_t*)p1;
  n2 = (nameval_t*)p2;
  return strcmp(n1->name, n2->name);
}

int lookup(char *name, nameval_t tab[], int ntab)
{
  nameval_t key, *np;

  key.name = name;
  key.value = 0; // just give it something (it isn't used)
  np = bsearch(&key, tab, ntab, sizeof (tab[0]), nvcmp);

  if (np == NULL) {
    return -1;
  }
  else {
    return np - tab;
  }
}

int addname(nameval_t newname)
{
  nameval_t *nvp;

  if (nvtab.nameval == NULL) { // first time
    nvtab.nameval = malloc(NVINIT * sizeof (nameval_t));
    if (NULL == nvtab.nameval) {
      return -1;
    }
    nvtab.max = NVINIT;
    nvtab.nval = 0;
  }
  else if (nvtab.nval >= nvtab.max) { // grow array
    nvp = realloc(nvtab.nameval, NVGROW * nvtab.max * sizeof (nameval_t));
    if (NULL == nvp) {
      return -1;
    }
    nvtab.max *= NVGROW;
    nvtab.nameval = nvp;
  }
  nvtab.nameval[nvtab.nval] = newname;
  return nvtab.nval++;
}

int delname(char *name)
{
  int i;
  for (i = 0; i < nvtab.nval; i++) {
    if (strcmp(nvtab.nameval[i].name, name) == 0) {
      // Free up the string for the entry we are going to delete
      free (nvtab.nameval[i].name);
      // Move the reset
      memmove(nvtab.nameval + i, nvtab.nameval + i + 1, (nvtab.nval - (i + 1)) * sizeof (nameval_t));
      nvtab.nval--;
      return 1;
    }
  }
  return 0;
}