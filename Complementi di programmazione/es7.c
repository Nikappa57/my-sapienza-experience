#include <stdio.h>

void	es7(void)
{
	int	n;
	int	min;

	printf("Ricerca minimo\n>> ");
	scanf("%d", &n);
	min = n;
	while (n)
	{
		if (min > n)
			min = n;
		printf(">> ");
		scanf("%d", &n);
	};
	printf("MIN: %d\n", min);
}
