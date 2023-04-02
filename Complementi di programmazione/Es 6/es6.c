void	to_uppercase(char *s)
{
	if (*s == '\0')
		return ;
	if (*s >= 'a' && *s <= 'z')
		*s -= 32;
	to_uppercase(s + 1);
}