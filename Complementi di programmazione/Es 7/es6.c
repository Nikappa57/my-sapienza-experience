#include "es7_1.h"

void	scl_positives(TipoSCL scl, TipoSCL *ris)
{
	if (scl == NULL)
		return ;
	if (scl->info >= 0)
	{
		(*ris) = (TipoSCL) malloc(sizeof(TipoNodoSCL));
		(*ris)->info = scl->info;
		scl_positives(scl->next, &((*ris)->next));
	}
	else
		scl_positives(scl->next, ris);
}

TipoSCL scl_positivesf(TipoSCL scl)
{
	TipoSCL	ris = NULL;

	scl_positives(scl, &ris);
	return (ris);
}
