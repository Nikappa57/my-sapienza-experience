void	copy(char *dest, char *src)
{
	*dest = *src;
	if (*src == '\0')
		return ;
	sopy(dest + 1, src + 1);
}