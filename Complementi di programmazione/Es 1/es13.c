#include <stdio.h>

void	es13(void)
{
	int	r;
	int	j;

	printf("Cerchio, raggio: ");
	scanf("%d", &r);
	for (int x = -r; x <= r; x++)
	{
		for (int y = -r; y <= r; y++)
		{
			if (x*x + y*y <= r*r)
				printf("*");
			else
				printf("-");
		}
		printf("\n");	
	}
}
