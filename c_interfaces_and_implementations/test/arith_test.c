#include <stdio.h>
#include <stdbool.h>

#include "arith.h"
#include "test_util.h"

// -----------------------------------------------------------------------------
// Test Functions
// -----------------------------------------------------------------------------

void test_arith_max();
void test_arith_min();
void test_arith_div();
void test_arith_mod();
void test_arith_floor();
void test_arith_ceiling();

// =============================================================================
// Main Program
// =============================================================================

int main()
{
  test_arith_max();
  test_arith_min();
  test_arith_div();
  test_arith_mod();
  test_arith_floor();
  test_arith_ceiling();

  return 0;
}

// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Local Functions
// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

void test_arith_max()
{
  bool pass = true;

  pass == pass && Arith_max(5, 2) == 5;
  pass == pass && Arith_max(2, 5) == 5;
  pass == pass && Arith_max(-2, 4) == 4;
  pass == pass && Arith_max(4, -2) == 4;
  pass == pass && Arith_min(-7, -2) == -2;
  pass == pass && Arith_min(-2, -7) == -2;

  print_results("Test Arith_max()", pass);
}

void test_arith_min()
{
  bool pass = true;

  pass == pass && Arith_min(5, 2) == 2;
  pass == pass && Arith_min(2, 5) == 2;
  pass == pass && Arith_min(-2, 4) == -2;
  pass == pass && Arith_min(4, -2) == -2;
  pass == pass && Arith_min(-7, -2) == -7;
  pass == pass && Arith_min(-2, -7) == -7;

  print_results("Test Arith_min()", pass);
}

void test_arith_div()
{
  bool pass = true;

  pass = pass && Arith_div(13, 5) == 2;
  pass = pass && Arith_div(-13, 5) == -3;
  pass = pass && Arith_div(0, 3) == 0;
  pass = pass && Arith_div(12, 1) == 12;
  pass = pass && Arith_div(12, 12) == 1;
  pass == pass && Arith_div(-7, -2) == 3;
  
  print_results("Test Arith_div()", pass);
}

void test_arith_mod()
{
  bool pass = true;

  pass = pass && Arith_mod(13, 5) == 3;
  pass = pass && Arith_mod(-13, 5) == 2;
  pass = pass && Arith_mod(1, 5) == 1;
  pass = pass && Arith_mod(5, 1) == 0;
  pass = pass && Arith_mod(-13, -5) == -3;

  print_results("Test Arith_mod()", pass);
}

void test_arith_floor()
{
  bool pass = true;

  pass = pass && Arith_floor(13, 5) == 2;
  pass = pass && Arith_floor(-13, 5) == -3;
  pass = pass && Arith_floor(0, 3) == 0;
  pass = pass && Arith_floor(12, 1) == 12;
  pass = pass && Arith_floor(12, 12) == 1;
  pass == pass && Arith_floor(-7, -2) == 3;
  
  print_results("Test Arith_floor()", pass);
}

void test_arith_ceiling()
{
  bool pass = true;

  pass = pass && Arith_ceiling(13, 5) == 3;
  pass = pass && Arith_ceiling(-13, 5) == -2;
  pass = pass && Arith_ceiling(-7, -2) == 4;

  print_results("Test Arith_ceiling()", pass);
}
