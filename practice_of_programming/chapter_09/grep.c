#include <stdio.h>
#include <string.h>

#include "util.h"

// -----------------------------------------------------------------------------
// Function Prototypes
// -----------------------------------------------------------------------------

int match(char *regex, char *text);
int match_here(char *regex, char *text);
int match_star(int c, char *regex, char *text);

int grep(char *regex, FILE *f, char *name);

// =============================================================================
// Main Program
// =============================================================================

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
  int i, nmatch;
  FILE *f;

  setprogname("grep");
  if (argc < 2)
    eprintf("usage: grep regex [file ...]");
  
  nmatch = 0;
  if (argc == 2) {
    if (grep(argv[1], stdin, NULL))
      nmatch++;
  }
  else {
    for (i = 2; i < argc; i++) {
      f = fopen(argv[i], "r");
      if (NULL == f) {
        weprintf("can't open %s:", argv[i]);
        continue;
      }
      if (grep(argv[1], f, argc > 3 ? argv[i] : NULL) > 0)
        nmatch++;
      fclose(f);
    }
  }
  return nmatch == 0;
}

// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Local Functions
// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

// match: search for regex anywhere in text
int match(char *regex, char *text)
{
  if (regex[0] == '^')
    return match_here(regex + 1, text);
  
  do { // must look even if string is empty
    if (match_here(regex, text))
      return 1;
  } while (*text++ != '\0');

  return 0;
}

// match_here: search for regex at beginning of text
int match_here(char *regex, char *text)
{
  if (regex[0] == '\0')
    return 1;
  if (regex[1] == '*')
    return match_star(regex[0], regex + 2, text);
  if (regex[0] == '$' && regex[1] == '\0')
    return *text == '\0';
  if (*text != '\0' && (regex[0] == '.' || regex[0] == *text))
    return match_here(regex + 1, text + 1);

  return 0;
}

// match_star: search for c * regex at beginning of text
int match_star(int c, char *regex, char *text)
{
  char *t;
  for (t = text; *t != '\0' && (*t == c || c == '.'); t++)
    continue;

  do { // a * matches zero or more instances
    if (match_here(regex, t))
      return 1;
  } while (t-- > text);

  return 0;
}

// grep: search for regex in file
int grep(char *regex, FILE *f, char *name)
{
  int n, nmatch;
  char buf[BUF_SIZE];

  nmatch = 0;
  while (fgets(buf, sizeof (buf), f) != NULL) {
    n = strlen(buf);
    if (n > 0 && buf[n - 1] == '\n')
      buf[n - 1] = '\0';
    if (match(regex, buf)) {
      nmatch++;
      if (name != NULL)
        printf("%s:", name);
      printf("%s\n", buf);
    }
  }
  return nmatch;
}
