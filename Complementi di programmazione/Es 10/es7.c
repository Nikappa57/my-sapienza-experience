#include "es10.h"

int	elemento_iesimo(Coda *c, int pos)
{
	T	val;

	while (pos-- > 0)
	{
		if (estCodaVuota(c))
			return (-1);
		val = outCoda(c);
	}
	return ((int)val);
}