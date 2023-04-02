#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int					*p;
	unsigned long long	a;

	a = (unsigned long long)&p;
	if (a < UINT_MAX)
		printf("unsigned int\n");
	else if (a < ULONG_MAX)
		printf("unsigned long int\n");
	else
		printf("unsigned long long int\n");
}