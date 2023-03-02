#include <stdio.h>

void	es12(void)
{
	int		n;
	float	x;
	float	f;

	printf("Calcolo Radice quadrata con il metodo di Newton\n x: ");
	scanf("%f", &x);
	printf("iterazionni: ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		if (!i)
			f = 1;
		else
			f = (f + (x / f)) / 2;
		printf("%f\n", f);

	}
	printf("Radice: %.4f\n", f);
}
