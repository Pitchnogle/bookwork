/*
This program demonstrates binary tree of nameval_t

The program works in a similar way to the array versions, but with a binary 
tree.

Example output:
Looking for entry in the tree:
The HTML character code for "&frac12;" is 0xBD

Looking for entry not in the tree:
The HTML character code for "&dummy;" was not found!

Looking for another entry in the tree
The HTML character code for "&cent;" is 0xA2
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// -----------------------------------------------------------------------------
// Data Structures
// -----------------------------------------------------------------------------

typedef struct nameval_t nameval_t;

struct nameval_t
{
  char *name;
  int value;
  nameval_t *left;
  nameval_t *right;
};

// -----------------------------------------------------------------------------
// Function Prototypes
// -----------------------------------------------------------------------------

void build(FILE *f);

nameval_t *new_item(char *name, int value);

nameval_t *insert(nameval_t *tree, nameval_t *newp);

nameval_t *lookup(nameval_t *tree, char *name);
nameval_t *nrlookup(nameval_t *tree, char *name);

void print_nv(nameval_t *p, void *arg);

void free_nv(nameval_t *p, void *arg);

void apply_inorder(nameval_t *tree, void (*func)(nameval_t*, void*), void *arg);

// =============================================================================
// Main Program
// =============================================================================

nameval_t *nvtree = NULL;

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

  // Let's look for an entry
  printf("Looking for entry in the tree:\n");
  char *s = "&frac12;";
  nameval_t *item = lookup(nvtree, s);
  if (NULL != item) {
    printf("The HTML character code for \"%s\" is 0x%X\n", s, item->value);
  }
  else {
    printf("The HTML character code for \"%s\" was not found!\n", s);
  }

  // Let's look for something not in the tree
  printf("\nLooking for entry not in the tree:\n");
  s = "&dummy;";
  item = lookup(nvtree, s);
  if (NULL != item) {
    printf("The HTML character code for \"%s\" is 0x%X\n", s, item->value);
  }
  else {
    printf("The HTML character code for \"%s\" was not found!\n", s);
  }

  // Let's look for another entry
  printf("\nLooking for another entry in the tree\n");
  s = "&cent;";
  item = nrlookup(nvtree, s);
  if (NULL != item) {
    printf("The HTML character code for \"%s\" is 0x%X\n", s, item->value);
  }
  else {
    printf("The HTML character code for \"%s\" was not found!\n", s);
  }

  // Let's display the tree
  // apply_inorder(nvtree, print_nv, "%s 0x%X\n");

  // Free the allocated memory
  apply_inorder(nvtree, free_nv, NULL);

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
    nvtree = insert(nvtree, new_item(buf, value));
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
  newp->left = NULL;
  newp->right = NULL;

  return newp;
}

nameval_t *insert(nameval_t *tree, nameval_t *newp)
{
  int cmp;

  if (NULL == tree) {
    return newp;
  }

  cmp = strcmp(newp->name, tree->name);
  if (0 == cmp) {
    // duplicate entries ignored
  }
  else if (cmp < 0) {
    tree->left = insert(tree->left, newp);
  }
  else {
    tree->right = insert(tree->right, newp);
  }

  return tree;
}

nameval_t *lookup(nameval_t *tree, char *name)
{
  int cmp;

  if (NULL == tree) {
    return NULL;
  }

  cmp = strcmp(name, tree->name);
  if (0 == cmp) {
    return tree;
  }
  else if (cmp < 0) {
    return lookup(tree->left, name);
  }
  else {
    return lookup(tree->right, name);
  }
}

nameval_t *nrlookup(nameval_t *tree, char *name)
{
  int cmp;

  while (tree != NULL) {
    cmp = strcmp(name, tree->name);
    if (0 == cmp) {
      return tree;
    }
    else if (cmp < 0) {
      tree = tree->left;
    }
    else {
      tree = tree->right;
    }
  }
  return NULL;
}

void print_nv(nameval_t *p, void *arg)
{
  char *fmt;
  fmt = (char*)arg;
  printf(fmt, p->name, p->value);
}

void free_nv(nameval_t *p, void *arg)
{
  free(p->name);
  free(p);
}

void apply_inorder(nameval_t *tree, void (*func)(nameval_t*, void*), void *arg)
{
  if (NULL == tree) return;
  
  apply_inorder(tree->left, func, arg);
  func(tree, arg);
  apply_inorder(tree->right, func, arg);
}

void apply_postorder(nameval_t *tree, void (*func)(nameval_t*, void*), void *arg)
{
  if (NULL == tree) return;
  
  apply_postorder(tree->left, func, arg);
  apply_postorder(tree->right, func, arg);
  func(tree, arg);
}
