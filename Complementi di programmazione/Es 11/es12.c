#include "es11.h"

// TODO
void set_albbinric(TipoAlbero a, TipoLista l)
{
	if (estListaVuota(l) || estVuoto(a))
		return ;
	if (estListaVuota(cdr(l)))
	{
		assegnaRadice(a, car(l));
		return ;
	}
	set_albbinric(sinistro(a), l);
	l = cdr(l);
	assegnaRadice(a, car(l));
	set_albbinric(destro(a), cdr(l));
}