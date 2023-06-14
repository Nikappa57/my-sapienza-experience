#include "es12.h"

int	list_len(TipoLista l)
{
	if (estListaVuota(l))
		return (0);
	return 1 + list_len(cdr(l));
}

T	*ltor(TipoLista l, int len)
{
	T	*result;

	result = (T *) malloc(sizeof(T) * len);
	for (; len > 0; len--, l = cdr(l))
		result[len - 1] = car(l);
	return result;
}

TipoAlbero albero_ricerca_arr(T *l, int start, int end)
{
	int			mid;
	TipoAlbero	result;

	if (start > end)
		return albBinVuoto();
	mid = (start + end) / 2;
	return creaAlbBin(l[mid],
			albero_ricerca_arr(l, start, mid - 1),
			albero_ricerca_arr(l, mid + 1, end));
}

TipoAlbero albero_ricerca(TipoLista l)
{
	T	*arr;
	int	len;

	len = list_len(l);
	arr = ltor(l, len);
	return albero_ricerca_arr(arr, 0, len - 1);
}