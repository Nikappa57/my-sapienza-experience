int	length(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + length(s + 1));
}