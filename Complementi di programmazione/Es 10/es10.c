#include "es10.h"

Coda	*elementi_pari(Coda *c)
{
	T		val;
	Coda	*result;

	result = codaVuota();
	while (!estCodaVuota(c))
		if ((val = outCoda(c)) % 2 == 0)
			inCoda(result, val);
	return (result);
}