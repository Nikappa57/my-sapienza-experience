#include <stdio.h>

int es14_get_pos(int val)
{
	int	base[] = {1, 2, 4, 5, 7, 8};
	int	len = 6;
	int i = 0;

	while (base[i] != val && i < 6)
		i++;
	if (base[i] == val || i < 6)
		return (i);
	else
		return (-1);
}

int	es14_check_perm(int n, int must_unique)
{
	int	base[] = {1, 2, 4, 5, 7, 8};
	int	check[] = {0, 0, 0, 0, 0, 0};
	int	len = 6;
	int i;

	while (n)
	{
		if (((i = es14_get_pos(n % 10)) != -1)
			&& (!check[i] || !must_unique))
			check[i] = 1;
		else
			return 0;
		n /= 10;
	}
	if (must_unique)
		for (int i = 0; i < len; i++)
			if (!check[i])
				return (0);
	return (1);

}

void	es14()
{
	int max = 875421;
	int	min = 124578;
	int	n_perm = 720;

	for (int i = min; i <= max; i++)
		if (es14_check_perm(i, 1) && es14_check_perm(i * 2, 0)
			&& es14_check_perm(i * 4, 0) && es14_check_perm(i * 5, 0)
			&& es14_check_perm(i * 6, 0))
			printf("Numero straordinario: %d\n", i);
}
