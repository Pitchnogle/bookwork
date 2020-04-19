#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "atom.h"
#include "mem.h"
#include "assert.h"
#include "except.h"

#include "test_util.h"

// -----------------------------------------------------------------------------
// Test Functions
// -----------------------------------------------------------------------------

void test_null_length_atom();
void test_null_string_atom();
void test_no_exist_string();
void test_int_atom();
void test_string_atom();

// =============================================================================
// Main Program
// =============================================================================

// Random string data
const char *str[] = {
  "jg5DhElfoef@3",
  "sW4kkEr45@21c",
  "3f#sdl!2mMEsd",
  "s$fGlTaBv49fG"
};

// Random number data
const int nums[] = {
  12345678,
  65345323,
  95439245,
  55820535
};

int main()
{
  test_null_length_atom();
  test_null_string_atom();
  test_no_exist_string();
  test_int_atom();
  test_string_atom();

  return 0;
}

// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Local Functions
// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

void test_null_length_atom()
{
  bool pass = true;
  bool caught;

  caught = false;
  TRY
    Atom_length(NULL);
  EXCEPT(Assert_Failed)
    caught = true;
  END_TRY;
  pass = pass && caught;

  caught = false;
  TRY
    // We haven't added this which violates contract
    Atom_length(str[0]);
  EXCEPT(Assert_Failed)
    caught = true;
  END_TRY;
  pass = pass && caught;

  print_results("Test NULL length atom()", pass);
}

void test_null_string_atom()
{
  bool pass = false;

  TRY
    Atom_string(NULL);
  EXCEPT(Assert_Failed)
    pass = true;
  END_TRY;

  print_results("Test NULL string atom()", pass);
}

void test_no_exist_string()
{
  bool pass = false;

  TRY
    Atom_length("~~ no exist ~~"); // check a string which hasn't been added
  EXCEPT(Assert_Failed)
    pass = true;
  END_TRY;

  print_results("Test no exist string atom()", pass);
}

void test_int_atom()
{
  bool pass = true;

  char str[43];

  int i;
  for (i = 0; i < sizeof (nums) / sizeof (nums[0]); i++) {
    snprintf(str, 43, "%d", nums[i]);
    const char *numstr = Atom_int(nums[i]);
    pass = pass && strcmp(str, numstr) == 0;
  }

  print_results("Test int atom()", pass);
}

void test_string_atom()
{
  bool pass = true;

  int i;
  for (i = 0; i < sizeof (str) / sizeof (str[0]); i++) {
    const char *s = Atom_string(str[i]);
    pass = pass && strcmp(str[i], s) == 0;
    pass = pass && Atom_length(str[i]) == strlen(str[i]);
  }

  print_results("Test string atom()", pass);
}
