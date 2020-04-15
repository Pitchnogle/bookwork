#include "assert.h"

const except_t assert_failed = {
  "Assertion failed"
};

void (assert)(int e)
{
  assert(e);
}
