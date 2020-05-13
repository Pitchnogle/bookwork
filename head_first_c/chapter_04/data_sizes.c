#include <stdio.h>
#include <limits.h>
#include <float.h>

int
main()
{
	printf("The value of INT_MAX is %d\n", INT_MAX);
	printf("The value of INT_MIN is %d\n", INT_MIN);
	printf("An int takes %lu bytes\n", sizeof(int));

	printf("The value of SHRT_MAX is %hd\n", SHRT_MAX);
	printf("The value of SHRT_MIN is %hd\n", SHRT_MIN);
	printf("A short takes %lu bytes\n", sizeof(short));

	printf("The value of FLT_MAX is %f\n", FLT_MAX);
	printf("The value of FLT_MIN is %.50f\n", FLT_MIN);
	printf("The value of FLT_MAX is %g\n", FLT_MAX);
	printf("The value of FLT_MIN is %g\n", FLT_MIN);
	printf("A float takes %lu bytes\n", sizeof(float));
}
