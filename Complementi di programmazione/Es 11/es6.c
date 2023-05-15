#include "es11.h"

TipoLista	albero_lista_aux(TipoAlbero a, TipoLista l)
{
	if (estVuoto(a))
		return (l);
	if (estFoglia(a))
		return (cons(radice(a), l));
	l = albero_lista_aux(destro(a), l);
	l = cons(radice(a), l);
	l = albero_lista_aux(sinistro(a), l);
	return (l);
}

TipoLista	albero_lista(TipoAlbero a)
{
	return (albero_lista_aux(a, listaVuota()));
}