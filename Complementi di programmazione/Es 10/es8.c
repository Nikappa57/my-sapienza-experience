#include "es10.h"

void	avoid_stampa(Coda *c, int elem)
{
	T		val;
	Coda	*aux;

	for (aux = codaVuota(); !estCodaVuota(c); )
	{
		val = outCoda(c);
		if (val != elem)
			printf("%d ", val);
		inCoda(aux, val);
	}
	*c = *aux;
	printf("\n");
}