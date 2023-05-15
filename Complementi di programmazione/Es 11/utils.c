#include "es11.h"

bool	estFoglia(TipoAlbero a)
{
	if (estVuoto(a))
		return (false);
	return (estVuoto(sinistro(a)) && estVuoto(destro(a)));
}

int	listLen(TipoLista l)
{
	if (estListaVuota(l))
		return (0);
	return (1 + listLen(cdr(l)));
}
