#include "es10.h"

Coda	*coda_circolare(Coda *c, int n)
{
	T		val;
	Coda	*aux;
	Coda	*result;

	result = codaVuota();
	for (int i = 0; i < n; )
	{
		aux = codaVuota();
		while (!estCodaVuota(c) && i++ < n)
		{
			val = outCoda(c);
			inCoda(aux, val);
			inCoda(result, val);
		}
		c = aux;
	}
	return (result);
}