#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	n;
	int	*buffer;

	printf("n: ");
	scanf("%d", &n);
	if (!(buffer = (int *) malloc(sizeof(int) * n)))
		return (printf("Error\n"));
	for (int i = 0; i < n; i++)
	{
		printf("[%p] %d\n", buffer + i, *(buffer + i));
	}
	return (0);
}
