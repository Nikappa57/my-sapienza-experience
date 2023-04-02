#include <stdlib.h>
#include <stdio.h>

char	ft_tolower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

int	main(void)
{
	void	*data;

	
	if (!(data = malloc(sizeof(char) + sizeof(float))))
		return (printf("Error\n"));
	printf("val: ");
	scanf("%f", (float *)(data + 1));
	fflush(stdin);
	printf("scale: ");
	scanf("%c", (char *)data);
	printf("%c, %f\n",  *(char *)data, *((float *)(data + 1)));

	switch (ft_tolower(*(char *)data))
	{
	case 'c':
		printf("K = %.2f\nF = %.2f\n",
			*(float *)(data + 1) + 273.15, *(float *)(data + 1) * 9 / 5 + 32);
		break;
	case 'k':
		printf("C = %.2f\nF = %.2f\n", 
			*(float *)(data + 1) - 273.15, (*(float *)(data + 1) - 273.15) * 9 / 5 + 32);
		break;
	case 'f':
		printf("C = %.2f\nK = %.2f\n", 
			(*(float *)(data + 1) - 32) * 5 / 9, (*(float *)(data + 1) - 32) * 5 / 9 + 273.15);
		break;
	
	default:
		printf("Scale not found\n");
		break;
	}
	free(data);
	return (0);
}
