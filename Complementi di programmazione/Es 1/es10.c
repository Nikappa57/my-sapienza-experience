#include <stdio.h>

void	es10(void)
{
	int	n;
	int	val;

	printf("Triangolo di Floyd\nn: ");
	scanf("%d", &n);
	val = 1;
	for (int l = 0; l < n; l++)
	{
		for (int i = 0; i <= l; i++)
			printf("%d ", val++);
		printf("\n");
	}
}
