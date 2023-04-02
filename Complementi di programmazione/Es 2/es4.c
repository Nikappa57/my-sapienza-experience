#include <stdio.h>
#include <limits.h>
#include <math.h>

int	main(void)
{
	printf("INT MAX: %d\n", INT_MAX);
	printf("LONG MAX: %ld\n", LONG_MAX);

	printf("INT MAX: %d\n", (int)(pow(2, sizeof(int) * 8 - 1) - 1.0f));
	printf("LONG MAX: %ld\n", (long)(pow(2, sizeof(long) * 8 - 1) - 1.0f));
}