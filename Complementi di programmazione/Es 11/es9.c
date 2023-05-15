#include "es11.h"

void scambia_foglie(TipoAlbero a)
{
	TipoAlbero		s;
	TipoAlbero		d;
	TipoInfoAlbero	tmp;

	if (estVuoto(a) || estFoglia(a))
		return ;
	s = sinistro(a);
	d = destro(a);
	if (estFoglia(s) && estFoglia(d))
	{
		tmp = radice(s);
		assegnaRadice(s, radice(d));
		assegnaRadice(d, tmp);
	}
	else
	{
		scambia_foglie(sinistro(a));
		scambia_foglie(destro(a));
	}
}