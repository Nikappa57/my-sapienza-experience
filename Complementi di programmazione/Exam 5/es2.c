#include "e5.h"

TipoLista	inFondo(TipoLista l)
{
	if (estVuota(l))
		return listaVuota();
	if (estVuota(cdr(l)))
		return cons(car(l), listaVuota());
	return cons(car(cdr(l)), inFondo(cons(car(l), cdr(cdr(l)))));
}

TipoLista	invertiInParte(TipoLista l, int inizio)
{
	if (estVuota(l))
		return listaVuota();
	if (inizio > 0)
		return cons(car(l), invertiInParte(cdr(l), inizio - 1));
	return inFondo(cons(car(l), invertiInParte(cdr(l), 0)));
}