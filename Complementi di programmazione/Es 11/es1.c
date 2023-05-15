#include "es11.h"

TipoInfoAlbero rad_max(TipoInfoAlbero e1, TipoInfoAlbero e2)
{
	if (e1 > e2)
		return e1;
	return (e2);
}

TipoInfoAlbero trova_massimo(TipoAlbero a)
{
	if (estVuoto(a))
		return (-1);
	if (estVuoto(sinistro(a)) && estVuoto(destro(a)))
		return radice(a);
	return rad_max(radice(a),
		rad_max(trova_massimo(sinistro(a)), trova_massimo(destro(a))));
}
