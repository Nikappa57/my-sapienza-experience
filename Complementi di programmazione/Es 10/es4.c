#include "es10.h"

bool	check_palindrome_r_helper(const char *s, int i1, int i2)
{
	if (i1 > i2)
		return (true);
	if (s[i1] != s[i2])
		return (false);
	return (check_palindrome_r_helper(s, i1 + 1, i2 - 1));
}

bool	check_palindrome_r(const char *s)
{
	return check_palindrome_r_helper(s, 0, strlen(s) - 1);
}