#include "es11.h"

int	cerca_livello(TipoAlbero a, TipoInfoAlbero v)
{
	int liv;

	if (estVuoto(a))
		return (-1);
	if (radice(a) == v)
		return (0);
	if ((liv = cerca_livello(sinistro(a), v)) != -1)
		return liv + 1;
	if ((liv = cerca_livello(destro(a), v)) != -1)
		return liv + 1;
	return (-1);
}