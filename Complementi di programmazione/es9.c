#include <stdio.h>

void	es9(void)
{
	int	n;
	int	input;
	int	nbr;

	nbr = 0;
	printf("Da bin a intero, inserire num bit: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("cifra %d: ", i);
		scanf("%d", &input);
		if (input == 1)
			nbr += pow(2, i);
	}
	printf("NUMERO: %d", nbr);
}
