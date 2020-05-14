#include <stdio.h>

typedef struct {
	unsigned char foo:4;
	unsigned char bar:2;
	unsigned char baz:2;
} my_bitfields;

typedef union {
	unsigned char value;
	my_bitfields bitfield;
} my_union;

int
main()
{
	my_union u = {0x75}; // sets value to 0x75

	printf("u.value = %#x\n", u.value);
	printf("u.bitfield.foo = %#x\n", u.bitfield.foo);
	printf("u.bitfield.bar = %#x\n", u.bitfield.bar);
	printf("u.bitfield.baz = %#x\n", u.bitfield.baz);

	return 0;
}
