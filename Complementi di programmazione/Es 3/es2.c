#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	int	*data;

	if (!(data = (int *) malloc(sizeof(int) * 2)))
		return printf("Error\n");
	*data = 0;
	do
	{
		printf(">> ");
		scanf("%d", (data + 1));
		if (*(data + 1) < 0)
			printf("nbr must be >= 0\n");
		else if (*(data + 1) != 0 && (*(data + 1) < *data || !*data))
			*data = *(data + 1);
	} while (*(data + 1) != 0);
	printf("MIN: %d\n", *data);
	free(data);
	return (0);
}
