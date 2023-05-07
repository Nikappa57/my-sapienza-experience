#include "es9.h"

TipoLista	doubledCopy(TipoLista list)
{
	TipoLista	tmp;
	TipoLista	result;

	for (result = listaVuota(); !estVuota(list); list = cdr(list))
	{
		result = append(car(list), result);
		result = append(car(list), result);
	}

	return (result);
}

TipoLista	doubledCopy_r(TipoLista list)
{
	if (estVuota(list))
		return (list);
	return (cons(car(list), cons(car(list), doubledCopy_r(cdr(list)))));
}