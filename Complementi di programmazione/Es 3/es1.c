#include <stdlib.h>
#include <stdio.h>

int	main()
{
	int	*tmp;
	int	*min;
	tmp = NULL;

	if (!(min = (int *) malloc(sizeof(int))))
		return printf("Error\n");
	*min = 0;
	do
	{
		if (tmp)
			free(tmp);
		if (!(tmp = (int *) malloc(sizeof(int))))
			return printf("Error\n");
		printf(">> ");
		scanf("%d", tmp);
		if (*tmp < 0)
			printf("nbr must be >= 0\n");
		else if (*tmp != 0 && (*tmp < *min || !*min))
			*min = *tmp;
	} while (*tmp != 0);
	free(tmp);
	printf("MIN: %d\n", *min);
	free(min);
	return (0);
}