#include "es7_1.h"

float	scl_sum(TipoSCL scl)
{
	if (scl == NULL)
		return (0.0f);
	return (scl->info + scl_sum(scl->next));
}
