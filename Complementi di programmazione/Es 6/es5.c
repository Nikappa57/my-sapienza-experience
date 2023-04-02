#include "fun.h"

bool	is_lowercase(char *s)
{
	if (*s == '\0')
		return (true);
	if (!(*s >= 'a' && *s <= 'z'))
		return (false);
	return (is_lowercase(s + 1));
}