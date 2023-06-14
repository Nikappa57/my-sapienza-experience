#include "es12.h"

int min(int a, int b)
{
	if (a == -1)
		return b;
	if (b == -1)
		return a;
	return a <= b ? a : b;
}

int	max(int a, int b)
{
	return a >= b ? a : b;
}

bool	estFoglia(TipoAlbero a)
{
	if (estVuoto(a))
		return false;
	return (estVuoto(sinistro(a))
		&& estVuoto(destro(a)));
}

TipoAlbero	estSingolo(TipoAlbero a)
{
	if (estVuoto(a))
		return false;
	if (!estVuoto(sinistro(a)) && estVuoto(destro(a)))
		return (sinistro(a));
	if (estVuoto(sinistro(a)) && !estVuoto(destro(a)))
		return (destro(a));
	return (albBinVuoto());
}

TipoInfoAlbero	val_min(TipoAlbero a)
{
	if (estVuoto(a))
		return (-1);
	return min(radice(a),
			min(val_min(sinistro(a)),
				val_min(destro(a))));
}

void	elimina_albero(TipoAlbero *a)
{
	if (!a || estVuoto(*a))
		return ;
	elimina_albero(&((*a)->sinistro));
	elimina_albero(&((*a)->destro));
	free(*a);
	*a = NULL;
}

int	numero_nodi(TipoAlbero a)
{
	if (estVuoto(a))
		return (0);
	return 1
		+ numero_nodi(sinistro(a))
		+ numero_nodi(sinistro(a));
}

TipoLista	init_r(T *vec, int len)
{
	if (len == 0)
		return (listaVuota());
	return (cons(*vec, init_r(vec + 1, len - 1)));
}