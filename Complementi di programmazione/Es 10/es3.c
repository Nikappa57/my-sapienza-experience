#include "es10.h"

bool	check_palindrome(const char *s)
{
	int		i;
	int		len;
	Pila	*stack;

	len = strlen(s);
	stack = codaVuota();
	for (i = 0; i < len / 2; i++)
		inPila(stack, s[i]);
	if (len % 2 != 0 && i + 1 < len)
		i++;
	while (i < len)
		if (s[i++] != outPila(stack))
			return (false);
	return (estPilaVuota(stack));
}