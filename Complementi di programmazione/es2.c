#include <stdio.h>

void	es2(void)
{
	int		i;
	float	n;
	float	sum;

	i = 0;
	n = 0;
	printf("Calcolo della media\n\n");
	do
	{
		printf(">> ");
		scanf("%f", &n);
		sum += n;
		i++;
	} while (n != 0);
	if (--i)
		printf("media: %.2f", sum / i);
}
