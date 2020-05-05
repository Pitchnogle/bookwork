#ifndef PACK_UNPACK_h
#define PACK_UNPACK_h

#include <stdint.h>
#include <stdarg.h>

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/**

*/
int pack(uint8_t *buf, char *fmt, ...);

/**

*/ 
int unpack(uint8_t *buf, char *fmt, ...);

#endif // PACK_UNPACK_h
