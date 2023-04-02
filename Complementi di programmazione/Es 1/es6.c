#include <stdio.h>

void	es6_swap_c(char *c1, char *c2)
{
	char	c;

	c = *c1;
	*c1 = *c2;
	*c2 = c;
}

void	es6(void)
{
	int		n, m, k = 0, l = 1;
	char	c1 = '*', c2='-';

	printf("Scacchiera N*M x N*M\nInserire n: ");
	scanf("%d", &n);
	do 
	{
		printf("Inserire m (multiplo di n): ");
		scanf("%d", &m);
	} while (n % m != 0);

	for (int i = 0; i < n * m; i++)
	{
		for (int j = 0; j < n * m; j++)
		{
			if (k++ >= m)
			{
				es6_swap_c(&c1, &c2);
				k = 1;
			}
			printf("%c", c1);
		}
		if ((m % 2 != 0) && (n % 2 != 0))
		{
			if (l < m)
				es6_swap_c(&c1, &c2);
			else
				l = 0;
		}
		else if (l >= m)
		{
			es6_swap_c(&c1, &c2);
			l = 0;
		}
		l++;
		printf("\n");
	}
}
