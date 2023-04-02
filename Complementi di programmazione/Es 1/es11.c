#include <stdio.h>

void	es11(void)
{
	int	n1;
	int	n2;
	int	mcm;

	printf("Calcolo mcm\nn1: ");
	scanf("%d", &n1);
	printf("n2: ");
	scanf("%d", &n2);
	mcm = 2;
	while ((mcm % n1 != 0) || (mcm % n2 != 0))
		mcm++;
	printf("mcm: %d\n", mcm);
}
