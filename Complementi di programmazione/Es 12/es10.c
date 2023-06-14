#include "es12.h"

TipoAlbero	*trova_liv_val_d(TipoAlbero *a,
		int livello, TipoInfoAlbero val, int d)
{
	TipoAlbero	*result;

	if (!a || estVuoto(*a) || (livello < 0))
		return NULL;
	if (livello == 0 && radice(*a) == val && d < 0)
		return a;
	if ((result = trova_liv_val_d(&((*a)->sinistro), livello - 1, val, d + livello)) != NULL)
		return result;
	else
		return trova_liv_val_d(&((*a)->destro), livello - 1, val, d - livello);
}

void scambia_uguali_livello_aux(TipoAlbero *a, int i_liv,
		int livello, int d, TipoAlbero *r)
{
	TipoAlbero	*b;
	TipoAlbero	tmp;

	if (!a || estVuoto(*a) || (i_liv < 0))
		return ;
	if (i_liv == 0 && (b = trova_liv_val_d(r, livello, radice(*a), d)))
	{
		tmp = *a;
		*a = *b;
		*b = tmp;
	}
	else
	{
		scambia_uguali_livello_aux(&((*a)->sinistro), i_liv - 1, livello, d - i_liv, r);
		scambia_uguali_livello_aux(&((*a)->destro), i_liv - 1, livello, d + i_liv, r);
	}
}

void	scambia_uguali_livello(TipoAlbero *a, int livello)
{
	scambia_uguali_livello_aux(a, livello, livello, 0, a);
}