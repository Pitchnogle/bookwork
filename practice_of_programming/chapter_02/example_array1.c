/*
This program demonstrates binary search of fixed array

In the program, we search for a specific HTML character code name, and show the
hex code if it was found.

Example output:
Search for an entry which exists in the table:
The HTML character code for "&frac12;" is 0xBD

Looking for an entry that isn't in the table:
The HTML character code for "&dummy;" was not found!
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "html_chars.h"

// -----------------------------------------------------------------------------
// MACROS
// -----------------------------------------------------------------------------

#define NELEMS(arr) (sizeof (arr) / sizeof (arr[0]))

// -----------------------------------------------------------------------------
// Function Prototypes
// -----------------------------------------------------------------------------

int scmp(const void *p1, const void *p2);
int nvcmp(const void *p1, const void *p2);

int lookup(char *name, nameval_t tab[], int ntab);

// =============================================================================
// Main Program
// =============================================================================

int main()
{
  // The lookup() function using a binary search which requires the html 
  // character table to be sorted!
  qsort(html_chars, NELEMS(html_chars), sizeof (html_chars[0]), scmp);

  // Look for an entry which exists in the table
  printf("Search for an entry which exists in the table:\n");
  char *s = "&frac12;";
  int i = lookup(s, html_chars, NELEMS(html_chars));
  if (i != -1) {
    int v = html_chars[i].value;
    printf("The HTML character code for \"%s\" is 0x%X\n", s, v);
  }
  else {
    printf("The HTML character code for \"%s\" was not found!\n", s);
  }

  // Look for an entry which isn't in the table
  printf("\nLooking for an entry that isn't in the table:\n");
  s = "&dummy;";
  i = lookup(s, html_chars, NELEMS(html_chars));
  if (i != -1) {
    int v = html_chars[i].value;
    printf("The HTML character code for \"%s\" is 0x%X\n", s, v);
  }
  else {
    printf("The HTML character code for \"%s\" was not found!\n", s);
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

// version 1
/*
int lookup(char *name, nameval_t tab[], int ntab)
{
  int low, high, mid, cmp;

  low = 0;
  high = ntab - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    cmp = strcmp(name, tab[mid].name);
    if (cmp < 0) {
      high = mid - 1;
    }
    else if (cmp > 0) {
      low = mid + 1;
    }
    else {
      return mid;
    }
  }
  return -1;
}
*/

// version 2
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
