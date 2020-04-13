// This program demonstrates binary search of growable array
//
// This starts with the example_array1.c example, but instead of using the
// predefined array in html_chars.h, we can add and delete entries from it
// as we go.

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

  // In this version, we will add a few entries to a growable name-value table
  // before we lookup anything
  addname((nameval_t){"&quot;", 0x22});
  addname((nameval_t){"&amp;", 0x26});
  addname((nameval_t){"&lt;", 0x3C});
  addname((nameval_t){"&gt;", 0x3E});
  addname((nameval_t){"&nbsp;", 0xA0});
  addname((nameval_t){"&iexcl;", 0xA1});
  addname((nameval_t){"&cent;", 0xA2});
  addname((nameval_t){"&frac12;", 0xBD});

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
  printf("\nAttempt to delete an entry:\n");
  if (!delname(s)) {
    printf("The HTML character code for \"%s\" was not found in table!\n", s);
  }
  else {
    printf("The HTML character code entry \"%s\" was deleted\n", s);
  }

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

  return 0;
}

// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Local Functions
// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

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
      memmove(nvtab.nameval + i, nvtab.nameval + i + 1, (nvtab.nval - (i + 1)) * sizeof (nameval_t));
      nvtab.nval--;
      return 1;
    }
  }
  return 0;
}