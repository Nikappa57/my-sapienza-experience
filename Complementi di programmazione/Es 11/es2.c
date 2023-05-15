#include "albero_binario.h"

TipoInfoAlbero	somma_foglie(TipoAlbero a)
{
	if (estVuoto(a))
		return (0);
	if (estVuoto(sinistro(a)) && estVuoto(destro(a)))
		return (radice(a));
	return (somma_foglie(sinistro(a)) + somma_foglie(destro(a)));
}