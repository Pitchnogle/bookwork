/*
This program demonstrates linked list of nameval_t

The program works in a similar way to the array version, but with a linked list.

Example output:
100 elements in nvlist

Looking for entry in the list:
The HTML character code for "&frac12;" is 0xBD

Looking for entry not in the list:
The HTML character code for "&dummy;" was not found!

Looking for another entry in the list
The HTML character code for "&cent;" is 0xA2

Attempt to delete an entry:
The HTML character code entry "&cent;" was deleted

After delete: nvlist has 99 elements

Looking for the just deleted entry:
The HTML character code for "&cent;" was not found!

Attempt to delete an entry not in the list:
The HTML character code for "&cent;" was not found in list!
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
  int value;
  nameval_t *next;
};

// -----------------------------------------------------------------------------
// Function Prototypes
// -----------------------------------------------------------------------------

void build(FILE *f);

nameval_t *new_item(char *name, int value);

nameval_t *add_front(nameval_t *list, nameval_t *newitem);
nameval_t *add_end(nameval_t *list, nameval_t *newitem);

nameval_t *del_item(nameval_t *list, char *name);

nameval_t *lookup(nameval_t *list, char *name);

void apply(nameval_t *list, void (*func)(nameval_t *, void*), void *arg);

void print_nv(nameval_t *p, void *arg);
void inc_counter(nameval_t *p, void *arg);

void free_all(nameval_t *list);

// =============================================================================
// Main Program
// =============================================================================

nameval_t *nvlist = NULL;

int main()
{
  // We read the html character table from a file
  const char *fname = "html_chars.txt";
  FILE *f = fopen(fname, "r");
  if (NULL == f) {
    printf("Unable to open %s\n", fname);
    exit (1);
  }
  build(f);
  fclose(f);

  // Display the list
  // apply(nvlist, print_nv, "%s 0x%X\n");

  // Count #elements in list
  int n = 0;
  apply(nvlist, inc_counter, &n);
  printf("%d elements in nvlist\n", n);

  // The list lookup isn't doing a binary search so we don't need to sort it

  // Let's look for an entry
  printf("\nLooking for entry in the list:\n");
  char *s = "&frac12;";
  nameval_t *item = lookup(nvlist, s);
  if (NULL != item) {
    printf("The HTML character code for \"%s\" is 0x%X\n", s, item->value);
  }
  else {
    printf("The HTML character code for \"%s\" was not found!\n", s);
  }

  // Let's look for something not in the list
  printf("\nLooking for entry not in the list:\n");
  s = "&dummy;";
  item = lookup(nvlist, s);
  if (NULL != item) {
    printf("The HTML character code for \"%s\" is 0x%X\n", s, item->value);
  }
  else {
    printf("The HTML character code for \"%s\" was not found!\n", s);
  }

  // Let's look for another entry
  printf("\nLooking for another entry in the list\n");
  s = "&cent;";
  item = lookup(nvlist, s);
  if (NULL != item) {
    printf("The HTML character code for \"%s\" is 0x%X\n", s, item->value);
  }
  else {
    printf("The HTML character code for \"%s\" was not found!\n", s);
  }

  // Let's delete that entry (it should be successful)
  printf("\nAttempt to delete an entry:\n");
  item = del_item(nvlist, s);
  if (NULL == item) {
    printf("The HTML character code for \"%s\" was not found in list!\n", s);
  }
  else {
    printf("The HTML character code entry \"%s\" was deleted\n", s);
  }
  
  // Count #elements in list (should be 1 less)
  n = 0;
  apply(nvlist, inc_counter, &n);
  printf("\nAfter delete: nvlist has %d elements\n", n);

  // Let's search again for the deleted entry (should not be found)
  printf("\nLooking for the just deleted entry:\n");
  item = lookup(nvlist, s);
  if (NULL != item) {
    printf("The HTML character code for \"%s\" is 0x%X\n", s, item->value);
  }
  else {
    printf("The HTML character code for \"%s\" was not found!\n", s);
  }

  // Let's attempt to delete non-existent entry
  printf("\nAttempt to delete an entry not in the list:\n");
  item = del_item(nvlist, s);
  if (NULL == item) {
    printf("The HTML character code for \"%s\" was not found in list!\n", s);
  }
  else {
    printf("The HTML character code entry \"%s\" was deleted\n", s);
  }

  free_all(nvlist);

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
    nvlist = add_front(nvlist, new_item(buf, value));
  }
}

nameval_t *new_item(char *name, int value)
{
  nameval_t *newp;

  newp = malloc(sizeof (nameval_t));
  if (NULL == newp) {
    exit(1);
  }
  newp->name = strdup(name);
  newp->value = value;
  newp->next = NULL;

  return newp;
}

nameval_t *add_front(nameval_t *list, nameval_t *newitem)
{
  newitem->next = list;
  return newitem;
}

nameval_t *add_end(nameval_t *list, nameval_t *newitem)
{
  nameval_t *p;

  if (NULL == list) {
    return newitem;
  }
  for (p = list; p->next != NULL; p = p->next)
    ;
  p->next = newitem;
  return list;
}

nameval_t *del_item(nameval_t *list, char *name)
{
  nameval_t *p, *prev;

  prev = NULL;
  for (p = list; p != NULL; p = p->next) {
    if (strcmp(name, p->name) == 0) {
      if (prev == NULL) {
        list = p->next;
      }
      else {
        prev->next = p->next;
      }
      free (p->name);
      free (p);

      return list;
    }
    prev = p;
  }
  // item not in list
  return NULL;
}

nameval_t *lookup(nameval_t *list, char *name)
{
  for ( ; list != NULL; list = list->next) {
    if (strcmp(name, list->name) == 0) {
      return list;
    }
  }
  return NULL;
}

void apply(nameval_t *list, void (*func)(nameval_t *, void*), void *arg)
{
  for ( ; list != NULL; list = list->next) {
    (*func)(list, arg);
  }
}

void print_nv(nameval_t *p, void *arg)
{
  char *fmt;
  fmt = (char*)arg;
  printf(fmt, p->name, p->value);
}

void inc_counter(nameval_t *p, void *arg)
{
  int *ip;
  ip = (int*)arg;
  (*ip)++;
}

void free_all(nameval_t *list)
{
  nameval_t *next;

  for ( ; list != NULL; list = list->next) {
    next = list->next;
    free (list->name);
    free (list);
  }
}
