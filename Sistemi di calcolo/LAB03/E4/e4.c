char	*my_strcpy(char *dest, const char *src)
{
	int	i = 0;
	do dest[i] = src[i];
	while (src[i++]);
	return (dest);
}