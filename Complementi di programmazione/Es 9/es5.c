#include "es9.h"

TipoLista	interleave(TipoLista l1, TipoLista l2)
{
	TipoLista	result;

	for (result = listaVuota(); !estVuota(l1); l1 = cdr(l1), l2 = cdr(l2))
	{
		result = append(car(l1), result);
		result = append(car(l2), result);
	}
	return (result);
}