#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdarg.h>

// -----------------------------------------------------------------------------
// Data Types
// -----------------------------------------------------------------------------

union float32
{
  uint32_t u32;
  float f32;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int pack(uint8_t *buf, char *fmt, ...) {
  va_list args;
  char *p;
  uint8_t *bp;

  uint16_t u16;    // 'h'
  uint32_t u32;    // 'i'
  union float32 f; // 'f'
  double d;
  char *str;       // 's'

  bp = buf;
  va_start(args, fmt);
  for (p = fmt; *p != '\0'; p++) {
    switch (*p) {
    case 'b': // int8_t, uint8_t
    case 'c': // char
      *bp++ = va_arg(args, int);
      break;

    case 'h': // int16_t, uint16_t
      u16 = va_arg(args, int);
      *bp++ = u16 >> 8;
      *bp++ = u16;
      break;

    case 'i': // int32_t, uint32_t
      u32 = va_arg(args, uint32_t);
      *bp++ = u32 >> 24;
      *bp++ = u32 >> 16;
      *bp++ = u32 >> 8;
      *bp++ = u32;
      break;

    case 'f': // float
      d = va_arg(args, double); // va_args doesn't work on float!
      f.f32 = (float)d;
      *bp++ = f.u32 >> 24;
      *bp++ = f.u32 >> 16;
      *bp++ = f.u32 >> 8;
      *bp++ = f.u32;
      break;
    
    case 's': // strings
      str = va_arg(args, char *);
      u32 = strlen(str);
      while (u32--) {
        *bp++ = *str++;
      }
      *bp++ = '\0';
      break;

    default:
      va_end(args);
      return -1;
    }
  }
  va_end(args);

  return bp - buf;
}

int unpack(uint8_t *buf, char *fmt, ...) {
  va_list args;
  char *p;
  uint8_t *bp;

  uint8_t *pu8;
  uint16_t *pu16;
  uint32_t *pu32;

  bp = buf;
  va_start(args, fmt);
  for (p = fmt; *p != '\0'; p++) {
    switch (*p) {
    case 'b': // int8_t, uint8_t
    case 'c': // char
      pu8 = va_arg(args, uint8_t *);
      *pu8 = *bp++;
      break;

    case 'h': // int16_t, uint16_t
      pu16 = va_arg(args, uint16_t *);
      *pu16  = *bp++ << 8;
      *pu16 |= *bp++;
      break;

    case 'i': // int32_t, uint32_t
    case 'f': // float
      pu32 = va_arg(args, uint32_t *);
      *pu32  = *bp++ << 24;
      *pu32 |= *bp++ << 16;
      *pu32 |= *bp++ << 8;
      *pu32 |= *bp++;
      break;
    
    case 's': // strings
      pu8 = va_arg(args, uint8_t *);
      while (*pu8++ = *bp++);
      break;

    default:
      va_end(args);
      return -1;
    }
  }
  va_end(args);

  return bp - buf; 
}
