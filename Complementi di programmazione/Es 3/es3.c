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
	float	*val;
	char	*scale;

	val = (float *) malloc(sizeof(float));
	scale = (char *) malloc(sizeof(char));
	if (!val || !scale)
		return (printf("Error\n"));
	printf("val: ");
	scanf("%f", val);
	fflush(stdin);
	printf("scale: ");
	scanf("%c", scale);

	switch (ft_tolower(*scale))
	{
	case 'c':
		printf("K = %.2f\nF = %.2f\n", *val + 273.15, *val * 9 / 5 + 32);
		break;
	case 'k':
		printf("C = %.2f\nF = %.2f\n", 
			*val - 273.15, (*val - 273.15) * 9 / 5 + 32);
		break;
	case 'f':
		printf("C = %.2f\nK = %.2f\n", 
			(*val - 32) * 5 / 9, (*val - 32) * 5 / 9 + 273.15);
		break;
	
	default:
		printf("Scale not found\n");
		break;
	}
	free(scale);
	free(val);
	return (0);
}
