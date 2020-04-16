#ifndef CSV_h
#define CSV_h

// -----------------------------------------------------------------------------
// Definitions
// -----------------------------------------------------------------------------

typedef struct csv_t *csv;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Public Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/*
Creates a new csv instance
*/
csv csv_new();

/*
Resets csv instance
*/
void csv_reset(csv csv);

/*
Reads one line from open input file f

- Assumes that input lines are terminated by \r, \n, \r\n, or EOF
- Returns pointer to line, with terminator removed, or NULL if EOF removed
- Line may be arbitrary in length; returns NULL if memory limit exceeded
- Line must be treated as read-only storage; caller must make a copy to
  preserve or change contents
*/
char *csv_getline(csv csv, FILE *f);

/*
Returns n-th field from last line read by csv_getline()

- Fields are numbered from 0
- Returns n-th field from last line read by csv_getline(); returns NULL if 
  n < 0 or beyond last field
- Fields are separated by commas
- Fields may be surrounded by "..."; such quotes are removed within "...", ""
  is replaced by " and comma is not a separator
- In unqouted fields, quotes are regular characters
- There can be an arbitrary number of fields of any length; returns NULL if
  memory limit exceeded
- Field must be treated as read-only storage; caller must make a copy to
  preserve or change contents
- Behavior undefined if called before csv_getline() is called
*/
char *csv_field(csv csv, int n);

/*
Returns number of fields on last line read by csv_getline()

Behavior undefined if called before csv_getline() is called
*/
int csv_nfield(csv csv);

#endif // CSV_h
