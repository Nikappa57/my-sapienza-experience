#include "es12.h"

TipoAlbero	aux(TipoAlbero a, int *len)
{
	int	len_s = *len;
	int	len_d = *len;
	TipoAlbero	s;
	TipoAlbero	d;
	TipoAlbero	result;

	if (estVuoto(a))
		return (a);
	s = aux(sinistro(a), &len_s);
	d = aux(destro(a), &len_d);
	result = creaAlbBin(radice(a), NULL, NULL);
	if (len_s >= len_d)
	{
		result->sinistro = s;
		(*len) += 1 + len_s;
	}
	else
	{
		result->destro = d;
		(*len) += 1 + len_d;
	}

	return result;
}

TipoAlbero	albero_percorso_lungo(TipoAlbero *a)
{
	int len = 0;

	return aux(*a, &len);
}