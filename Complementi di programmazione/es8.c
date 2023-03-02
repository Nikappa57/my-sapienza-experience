#include <stdio.h>

void	es8(void)
{
	int	n;

	printf("Rappresentazione numeri con *, \n>> ");
	scanf("%d", &n);
	while (n)
	{
		for (int i = 0; i < n; i++)
			printf("*");
		printf("\n>> ");
		scanf("%d", &n);
	}
}
