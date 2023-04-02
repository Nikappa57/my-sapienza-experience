#include "fun.h"

bool	same_content(FILE *f1, FILE *f2)
{
	char	c1;
	char	c2;

	c1 = fgetc(f1);
	c2 = fgetc(f2);
	if (c1 != c2)
		return (false);
	if (c1 == EOF && c2 == EOF)
		return (true);
	return (same_content(f1, f2));
}