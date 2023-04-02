#include <stdio.h>

void	es5(void)
{
	int	n, f, f0, f1;

	f = 0;
	f0 = 0;
	f1 = 1;
	printf("Successione di fibonacci\nInserire il n: ");
	scanf("%d", &n);
	for (int i=0; i<n; i++)
	{
		f0 = f1;
		f1 = f;
		printf("%d ", f);
		f = f0 + f1;
	}
	printf("\n");
}
