#include <stdio.h>

int	main(void)
{
	char	a;
	short	b;
	int		c;
	long	d;
	float	e;
	double	f;

	printf("char: %lu byte\n", sizeof(a));
	printf("short: %lu byte\n", sizeof(b));
	printf("int: %lu byte\n", sizeof(c));
	printf("long: %lu byte\n", sizeof(d));
	printf("float: %lu byte\n", sizeof(e));
	printf("double: %lu byte\n", sizeof(f));
}