#include "es11.h"

int	check_singoli(TipoAlbero a)
{
	if (!estVuoto(sinistro(a)) ^ !estVuoto(destro(a)))
		return (radice(a));
	return (0);
}

int somma_singoli(TipoAlbero a)
{
	if (estVuoto(a))
		return (0);
	return (check_singoli(a)
		+ somma_singoli(sinistro(a))
		+ somma_singoli(destro(a)));
}