#include "es12.h"

void	rimuovi_foglie_profonde(TipoAlbero *a, int n)
{
	if (!a || estVuoto(*a) || (n < 0))
		return ;
	if (n == 0 && estFoglia(*a))
	{
		free(*a);
		*a = NULL;
	}
	else
	{
		rimuovi_foglie_profonde(&((*a)->sinistro), n - 1);
		rimuovi_foglie_profonde(&((*a)->destro), n - 1);
	}
}