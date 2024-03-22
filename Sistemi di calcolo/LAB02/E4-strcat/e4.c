// scrivere la soluzione qui...
#include <stdlib.h>

static unsigned int ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

char *my_strcat(char *dest, const char *src)
{
	char	*result;
	int		i;
	int		j;

	if (!(result = (char *) malloc(
			sizeof(char) * (ft_strlen((char *)src) + ft_strlen(dest) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
		dest[i++] = src[j++];
	dest[i] = '\0';
	return dest;
}
