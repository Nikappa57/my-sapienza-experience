#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int		*allocaInt(void);
void	printInt(int *i1, int *i2);
void	soluzioneEquazione(int a, int b, int c);
int 	mcm(int i1, int i2);
int 	MCD(int i1, int i2);

int	main(void)
{
	int	*a;
	int	*b;
	int	*c;

	a = allocaInt();
	b = allocaInt();
	c = allocaInt();
	printf("coeff: ");
	scanf("%d %d %d", a, b, c);
	soluzioneEquazione(*a, *b, *c);
	free(a);
	free(b);
	free(c);
	return (0);
}

int	*allocaInt(void)
{
	return ((int *)malloc(sizeof(int)));
}

void	printInt(int *i1, int *i2)
{
	printf("%d | %d\n", *i1, *i2);
}

void	soluzioneEquazione(int a, int b, int c)
{
	int	d;

	d = pow(b, 2) - 4 * a * c;
	printf("Result: ");
	if (a == 0)
	{
		if (b != 0)
			printf("%lf\n", (-(double)c/(double)b));
		else if (b == 0 && c == 0)
			printf("R\n");
		else
			printf("imp\n");
	}
	else if (d == 0)
		printf("%lf\n", (-(double)b / (2 * (double)a)));
	else if (d < 0)
		printf("imp\n");
	else
		printf("%lf, %lf\n",
			((-(double)b - sqrt((double)d)) / (2 * (double)a)),
			((-(double)b + sqrt((double)d)) / (2 * (double)a)));
}

int 	MCD(int i1, int i2)
{
	int	d;

	d = i1 >= i2 ? i1 : i2;
	while ((i1 % d != 0) && (i2 % d != 0))
		d--;
	return (d);
}

int 	mcm(int i1, int i2)
{
	return (i1 * i2 / MCD(i1, i2));
}