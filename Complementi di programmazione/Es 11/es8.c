#include "es11.h"

int	somma_sottoalbero_aux(TipoAlbero a)
{
	int	r = radice(a);

	if (estVuoto(a))
		return (0);
	if (estFoglia(a))
		return (radice(a));
	assegnaRadice(a, somma_sottoalbero_aux(sinistro(a))
			+ somma_sottoalbero_aux(destro(a)));
	return (radice(a) + r);
}

void somma_sottoalbero(TipoAlbero a)
{
	somma_sottoalbero_aux(a);
}