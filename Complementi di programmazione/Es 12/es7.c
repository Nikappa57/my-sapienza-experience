#include "es12.h"

int	somma_free(TipoAlbero *a)
{
	int	r;

	if (!a || estVuoto(*a))
		return 0;
	r = radice(*a)
		+ somma_free(&((*a)->sinistro))
		+ somma_free(&((*a)->destro));
	free(*a);
	*a = NULL;
	return r;
}

void	comprimi_sottoalberi(TipoAlbero *a)
{
	if (!a || estVuoto(*a))
		return ;
	if (!estVuoto(sinistro(*a)) && estVuoto(destro(*a)))
		(*a)->info = somma_free(&((*a)->sinistro));
	else if (estVuoto(sinistro(*a)) && !estVuoto(destro(*a)))
		(*a)->info = somma_free(&((*a)->destro));
	else
	{
		comprimi_sottoalberi(&((*a)->sinistro));
		comprimi_sottoalberi(&((*a)->destro));
	}
}