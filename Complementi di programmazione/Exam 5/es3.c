#include "e5.h"

bool	estFoglia(TipoAlbero a)
{
	if (estVuoto(a))
		return false;
	return (estVuoto(sinistro(a))
		&& estVuoto(destro(a)));
}

TipoAlbero	prodottoVicini(TipoAlbero a)
{
	TipoInfoAlbero	r;

	if (estVuoto(a))
		return albBinVuoto();
	r = radice(a);
	if (!estVuoto(sinistro(a)))
		r *= radice(sinistro(a));
	if (!estVuoto(destro(a)))
		r *= radice(destro(a));
	return creaAlbBin(r,
			prodottoVicini(sinistro(a)),
			prodottoVicini(sinistro(a)));
}