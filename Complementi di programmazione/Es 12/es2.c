#include "es12.h"

void duplica_foglie(TipoAlbero *a)
{
	if (estVuoto(*a))
		return ;
	if (estFoglia(*a))
		(*a)->sinistro = creaAlbBin(
			radice(*a), NULL, NULL);
	else
	{
		duplica_foglie(&((*a)->sinistro));
		duplica_foglie(&((*a)->destro));
	}
}