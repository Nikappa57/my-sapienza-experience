#include "es12.h"

void	scambia_sottoalberi_simili(TipoAlbero *a)
{
	TipoAlbero	tmp;

	if (!a || estVuoto(*a))
		return ;
	if (numero_nodi(sinistro(*a)) == numero_nodi(destro(*a)))
		tmp = sinistro(*a);
		(*a)->sinistro = (*a)->destro;
		(*a)->destro = tmp;
	scambia_sottoalberi_simili(&((*a)->sinistro));
	scambia_sottoalberi_simili(&((*a)->destro));
}