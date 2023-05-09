#include "aux.h"

void sorted_merge(TipoSCL scl1, TipoSCL scl2, TipoSCL *ris)
{
	if (scl1 == NULL && scl2 == NULL)
    {
      ris = NULL;
      return ;
    }
	(*ris) = (TipoSCL) malloc(sizeof(TipoNodoSCL));
	if ((scl2 == NULL) || (scl1 != NULL && scl1->info <= scl2->info))
	{
		(*ris)->info = scl1->info;
		sorted_merge(scl1->next, scl2, &((*ris)->next));
	}
	else
	{
		(*ris)->info = scl2->info;
		sorted_merge(scl1, scl2->next, &((*ris)->next));
	}
}