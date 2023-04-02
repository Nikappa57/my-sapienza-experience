#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	long	a = 4;
	long	b = 5;
	long	*pa;
	long	*pb;
	long	dist;

	pa = &a;
	pb = &b;
	dist = labs(pa - pb);
	printf("pa: %p, pb: %p\n", pa, pb);
	printf("|pb - pa|: %ld\n", dist);
	*pa = *pb + dist;
	printf("a: %ld\n", a);
}