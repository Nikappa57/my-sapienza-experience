#include "es12.h"

void	limita_livello(TipoAlbero *a, int livello)
{
	if (!a || estVuoto(*a))
		return ;
	limita_livello(&((*a)->sinistro), livello - 1);
	limita_livello(&((*a)->destro), livello - 1);
	if (livello <= 0)
	{
		free(*a);
		*a = NULL;
	}
}