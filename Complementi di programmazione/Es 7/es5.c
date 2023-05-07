#include "es7_1.h"

void	scl_duplicate_pos(TipoSCL scl, int pos)
{
	TipoSCL	tmp;

	if (scl == NULL)
		return ;
	if (pos == 0)
	{
		tmp = (TipoSCL) malloc(sizeof(TipoNodoSCL));
		tmp = scl;
		tmp->info = scl->info;
		tmp->next = scl->next;
		scl->next = tmp;
	}
	else
		scl_duplicate_pos(scl->next, pos - 1);
	return ;
}
