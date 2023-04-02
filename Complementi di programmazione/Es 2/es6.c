#include <stdio.h>

int	main(void)
{
	int i = 10;
	int j = -1;
	char *p, *q;

	p = (char *)&i;
	q = (char *)&j;
	for (int k = 0; k < sizeof(int); k++)
		*(q + k) = *(p + k);
	printf("%d == %d\n", i, j);
}