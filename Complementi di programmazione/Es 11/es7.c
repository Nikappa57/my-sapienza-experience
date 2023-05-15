#include "es11.h"

TipoLista percorso_lungo(TipoAlbero a)
{
	TipoLista	d;
	TipoLista	s;

	if (estVuoto(a))
		return (listaVuota());
	s = cons(radice(a), percorso_lungo(sinistro(a)));
	d = cons(radice(a), percorso_lungo(destro(a)));
	if (listLen(s) >= listLen(d))
		return (s);
	return (d);
}