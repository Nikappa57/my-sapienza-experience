#include "es12.h"

void	rimuovi_nodo_val(TipoAlbero *a, TipoInfoAlbero val)
{
	if (!a || estVuoto(*a))
		return ;
	if (radice(*a) == val)
		elimina_albero(a);
	else
	{
		rimuovi_nodo_val(&((*a)->sinistro), val);
		rimuovi_nodo_val(&((*a)->destro), val);
	}

}

void	rimuovi_minimo(TipoAlbero *a)
{
	printf("min: %d\n", val_min(*a));
	rimuovi_nodo_val(a, val_min(*a));
}