#include <stdio.h>

int	count_substrings(const char* s, const char* sub)
{
	int			count = 0;
	const char	*tmp = sub;

	do {
		if (*s == *tmp) {
			if (!*++tmp) {
				count++;
				s -= tmp - 1 - sub;
				tmp = sub;
			}
		} else tmp = sub;
	} while (*++s);
	return (count);
}
