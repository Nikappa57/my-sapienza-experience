#include "fun.h"

bool	is_any_lowercase(char *s)
{
	if (*s == '\0')
		return (false);
	if (*s >= 'a' && *s <= 'z')
		return (true);
	return (is_any_lowercase(s + 1));
}