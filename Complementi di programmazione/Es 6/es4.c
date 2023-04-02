int	char_position(char *s, char ch)
{
	int	pre;

	if (*s == ch)
		return (0);
	if (*s == '\0')
		return (-1);
	if ((pre = char_position(s + 1, ch)) == -1)
		return (-1);
	return (1 + pre);
}