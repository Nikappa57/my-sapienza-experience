#include "es11.h"

void max_figli_livello(TipoAlbero a, int livello)
{
	TipoAlbero	s;
	TipoAlbero	d;

	if (estVuoto(a) || estFoglia(a))
		return ;
	if (livello > 0)
	{
		max_figli_livello(sinistro(a), livello - 1);
		max_figli_livello(destro(a), livello - 1);
		return ;
	}
	s = sinistro(a);
	d = destro(a);
	if (!estVuoto(s) && !estVuoto(d))
		assegnaRadice(a, radice(s) > radice(d) ? radice(s) : radice(d));
	else if (!estVuoto(s))
		assegnaRadice(a, radice(s));
	else
		assegnaRadice(a, radice(d));
}