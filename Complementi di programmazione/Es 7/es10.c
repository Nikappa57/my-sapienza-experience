#include "es7_2.h"

void	sclstring_remove(TipoSCL *scl_p, char val)
{
	TipoSCL tmp;

	if ((*scl_p) == NULL)
		return ;
	if ((*scl_p)->info == val)
	{
		tmp = *scl_p;
		(*scl_p) = tmp->next;
		free(tmp);
		tmp = NULL;
		sclstring_remove(scl_p, val);
	}
	else
		sclstring_remove(&((*scl_p)->next), val);

}