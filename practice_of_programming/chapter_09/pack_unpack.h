/*
Utility to pack/unpack binary data to/from buffer

The **fmt** argument is a string where the characters provided represent the 
data to pack/unpack:
- "b" -- int8_t/uint8_t
- "c" -- char
- "h" -- int16_t/uint16_t
- "i" -- int32_t/uint32_t
- "f" -- float
- "s" -- char* (c-string)

Since the functions are variadic, the whole point is to be able to pack/unpack
an arbitrary number of values easily.
*/
#ifndef PACK_UNPACK_h
#define PACK_UNPACK_h

#include <stdint.h>
#include <stdarg.h>

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/**
Pack binary items into buffer

@return the length of the packed buffer
*/
int pack(uint8_t *buf, char *fmt, ...);

/**
Unpack packed items from buffer

@return the length of data unpacked
*/ 
int unpack(uint8_t *buf, char *fmt, ...);

#endif // PACK_UNPACK_h
