#include "es9.h"

TipoLista	init(T *vec, int len)
{
	TipoLista	list;

	list = listaVuota();
	while (len > 0)
		list = cons(vec[--len], list);
	return (list);
}

TipoLista	init_r(T *vec, int len)
{
	if (len == 0)
		return (listaVuota());
	return (cons(*vec, init_r(vec + 1, len - 1)));
}