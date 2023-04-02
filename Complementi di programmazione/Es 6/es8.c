void	concat(char *dest, const char *src)
{
	if (*dest != '\0')
		concat(dest + 1, src);
	*dest = *src;
	if (*src == '\0')
		return ;
	*(dest + 1) = '\0';
	concat(dest + 1, src + 1);
}