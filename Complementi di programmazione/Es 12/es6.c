#include "es12.h"

TipoInfoAlbero	max_liv_val(TipoAlbero a, int livello)
{
	if (estVuoto(a) || livello < 0)
		return (0);
	if (livello == 0)
		return radice(a);
	return max(
		max_liv_val(sinistro(a), livello - 1),
		max_liv_val(sinistro(a), livello - 1));
}

void	rimuovi_val_liv(TipoAlbero *a, TipoInfoAlbero val, int livello)
{
	if (!a || estVuoto(*a) || (livello < 0))
		return ;
	if (livello == 0 && radice(*a) == val)
		elimina_albero(a);
	else
	{
		rimuovi_val_liv(&((*a)->sinistro), val, livello - 1);
		rimuovi_val_liv(&((*a)->destro), val, livello - 1);
	}
}

void	rimuovi_max_livello(TipoAlbero *a, int livello)
{
	if (!a || estVuoto(*a) || livello < 0)
		return ;
	rimuovi_val_liv(a, max_liv_val(*a, livello), livello);
}