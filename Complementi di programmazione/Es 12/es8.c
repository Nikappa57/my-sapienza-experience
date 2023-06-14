#include "es12.h"

void	sx_pari_dx_dispari(TipoAlbero *a)
{
	if (!a || estVuoto(*a))
		return ;
	if (radice(*a) % 2 == 0)
	{
		if (!estVuoto(sinistro(*a)))
			elimina_albero(&((*a)->sinistro));
		if (estVuoto(destro(*a)))
			(*a)->sinistro = creaAlbBin(radice(*a), NULL, NULL);
		else
			sx_pari_dx_dispari(&((*a)->destro));
	}
	else
	{
		if (!estVuoto(destro(*a)))
			elimina_albero(&((*a)->destro));
		if (estVuoto(sinistro(*a)))
			(*a)->destro = creaAlbBin(radice(*a), NULL, NULL);
		else
			sx_pari_dx_dispari(&((*a)->sinistro));
	}
}
