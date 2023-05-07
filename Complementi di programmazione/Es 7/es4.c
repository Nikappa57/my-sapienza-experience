#include "es7_1.h"

float	scl_dot(TipoSCL scl1, TipoSCL scl2)
{
	if ((scl1 == NULL) || (scl2 == NULL))
		return (0);
	return (scl1->info * scl2->info + scl_dot(scl1->next, scl2->next));
}
