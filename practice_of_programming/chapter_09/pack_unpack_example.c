/*
This is an example of how to use the pack/unpack in a simluated socket style
program. We pack and then unpack a few times.

This could be the basis for a command-handler for an embedded system. The code
is clean and simple. Note the use of the unpacking function array.

The weakness in this particular example is the requirement to know the message
length. The way this implementation is written, an error return is generated if
the length is wrong. The trick would be how to know this number all the time.
For example, what if multiple messages were passed to the buffer? The way I read
this, we're hosed.

Faced a similar circumstance recently using Protocol Buffers. Since the length
also needed to be known, it was sent in advance of any message. Not ideal but
there in no standard way to handle this in protocol buffers.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

#include "pack_unpack.h"
#include "util.h"

// -----------------------------------------------------------------------------
// Function Prototypes
// -----------------------------------------------------------------------------

void receive(int network);

int read_packet(int network, uint8_t *buf, int n);

int pack_type0(uint8_t *buf, uint16_t count, uint8_t val);
int pack_type1(uint8_t *buf, uint16_t count, uint8_t val, uint32_t data);
int pack_type2(uint8_t *buf, uint16_t count, uint32_t dw1, uint32_t dw2);

int unpack_type0(int n, uint8_t *buf);
int unpack_type1(int n, uint8_t *buf);
int unpack_type2(int n, uint8_t *buf);

int process_type0(uint16_t count, uint8_t val);
int process_type1(uint16_t count, uint8_t val, uint32_t data);
int process_type2(uint16_t count, uint32_t dw1, uint32_t dw2);

// =============================================================================
// Main Program
// =============================================================================

#define BUF_SIZE 1024

int (*unpack_func[])(int, uint8_t *) = {
  unpack_type0,
  unpack_type1,
  unpack_type2,
};

#define NELEMS(arr) (sizeof (arr) / sizeof (arr[0]))

uint8_t wr_buf[BUF_SIZE];
int wr_len;

int main()
{
  // Let's pack and unpack a type1 message
  wr_len = pack_type1(wr_buf, 0, 99, 12345678);
  receive(0);

  // Let's pack and unpack a type2 message
  wr_len = pack_type2(wr_buf, 1, 1234, 56789);
  receive(0);

  return 0;
}

// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Local Functions
// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

void receive(int network)
{
  uint8_t type, buf[BUF_SIZE];
  int n;

  while ((n = read_packet(network, buf, BUF_SIZE)) > 0) {
    type = buf[0];
    if (type >= NELEMS(unpack_func))
      eprintf("bad packet type %#02x", type);
    if ((*unpack_func[type])(n, buf) < 0)
      eprintf("protocol error, type %#02x length %d", type, n);
  }
}

int read_packet(int network, uint8_t *buf, int n)
{
  // This is a simulated communication function. In this example, we just get
  // the buffer count. In a socket program, for example, we would be able to 
  // get the #bytes read. We are simulating this here.
  memcpy(buf, wr_buf, wr_len);
  int rd_len = wr_len;

  // Once we simulated the read, empty the buffer so we can use it again
  memset(wr_buf, 0, wr_len);
  wr_len = 0;

  return rd_len;
}

int pack_type0(uint8_t *buf, uint16_t count, uint8_t val)
{
  return pack(buf, "bhb", 0x00, count, val);
}

int pack_type1(uint8_t *buf, uint16_t count, uint8_t val, uint32_t data)
{
  return pack(buf, "bhbi", 0x01, count, val, data);
}

int pack_type2(uint8_t *buf, uint16_t count, uint32_t dw1, uint32_t dw2)
{
  return pack(buf, "bhii", 0x02, count, dw1, dw2);
}

int unpack_type0(int n, uint8_t *buf)
{
  uint8_t type, val;
  uint16_t count;

  if (unpack(buf, "bhb", &type, &count, &val) != n)
    return -1;
  
  assert(type == 0x00);
  return process_type0(count, val);
}

int unpack_type1(int n, uint8_t *buf)
{
  uint8_t type, val;
  uint16_t count;
  uint32_t data;
  if (unpack(buf, "bhbi", &type, &count, &val, &data) != n)
    return -1;

  assert(type == 0x01);
  return process_type1(count, val, data);
}

int unpack_type2(int n, uint8_t *buf)
{
  uint8_t type;
  uint16_t count;
  uint32_t dw1, dw2;

  if (unpack(buf, "bhii", &type, &count, &dw1, &dw2) != n)
    return -1;
  
  assert(type == 0x02);
  return process_type2(count, dw1, dw2);
}

int process_type0(uint16_t count, uint8_t val)
{
  // In this example program we just print out the values. In a more practical
  // example, we could do much more
  int n = fprintf(stdout, "process_type1: count= %hu, val= %#x\n", count, val);
  return n;
}

int process_type1(uint16_t count, uint8_t val, uint32_t data)
{
  // In this example program we just print out the values. In a more practical
  // example, we could do much more
  int n = fprintf(stdout, "process_type1: count= %hu, val= %#x, data= %u\n", count, val, data);
  return n;
}

int process_type2(uint16_t count, uint32_t dw1, uint32_t dw2)
{
  // In this example program we just print out the values. In a more practical
  // example, we could do much more
  int n = fprintf(stdout, "process_type2: count= %hu, dw1= %u, dw2= %u\n", count, dw1, dw2);
  return n;
}
