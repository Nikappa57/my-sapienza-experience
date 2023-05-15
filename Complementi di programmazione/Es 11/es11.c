#include "es11.h"

void scambia_foglie_livello(TipoAlbero a, int livello)
{
	TipoAlbero		s;
	TipoAlbero		d;
	TipoInfoAlbero	tmp;

	if (estVuoto(a) || estFoglia(a))
		return ;
	if (livello - 1 > 0)
	{
		scambia_foglie_livello(sinistro(a), livello - 1);
		scambia_foglie_livello(destro(a), livello - 1);
		return ;
	}
	s = sinistro(a);
	d = destro(a);
	if (!estVuoto(s) && !estVuoto(d))
	{
		tmp = radice(s);
		assegnaRadice(s, radice(d));
		assegnaRadice(d, tmp);
	}
}