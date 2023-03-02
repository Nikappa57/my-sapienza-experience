#include <stdio.h>

void	es1(void)
{
	float	a;
	float	b;

	printf("Risolvi l'equazione del tipo ax + b = 0\na: ");
	scanf("%f", &a);
	printf("b: ");
	scanf("%f", &b);
	printf("%.2f", -b/a);
}
