#include <stdio.h>

void	es3(void)
{
	int	n;

	printf("Inserire la grandezza del quadrato: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("*");
		printf("\n");
	}
}
