#include "es9.h"

TipoLista	subList(TipoLista list, int start, int end)
{
	TipoLista	result;

	for (int i = 0; i < start && !estVuota(list); i++)
		list = cdr(list);
	for (result = listaVuota(); start <= end && !estVuota(list); start++, list = cdr(list))
		result = append(car(list), result);
	return (result);
}

TipoLista	subList_r(TipoLista list, int start, int end)
{
	if (estVuota(list))
		return (list);
	if (start > 0)
		return (subList_r(cdr(list), start - 1, end - 1));
	if (end <= 0)
		return (listaVuota());
	return (cons(car(list), subList(cdr(list), start, end - 1)));
}