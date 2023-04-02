int	char_last_position(char *s, char ch)
{
	int	pre;

	if (*s == '\0')
		return (-1);
	pre = char_last_position(s + 1, ch);
	return (pre + (*s == ch || pre != -1));
}