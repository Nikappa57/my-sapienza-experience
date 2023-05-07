#include "es9.h"

TipoLista	multipleSublist(TipoLista list, unsigned int m)
{
	TipoLista	result;

	for (result = listaVuota(); !estVuota(list); list = cdr(list))
	{
		if (car(list) % m == 0)
			result = append(car(list), result);
	}
	return (result);
}

TipoLista	multipleSublist_r(TipoLista list, unsigned int m)
{
	if (estVuota(list))
		return (list);
	if (car(list) % m != 0)
		return (multipleSublist_r(cdr(list), m));
	return (cons(car(list), multipleSublist_r(cdr(list), m)));
	
}