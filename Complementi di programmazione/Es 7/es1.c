#include "es7_1.h"

int	scl_len(TipoSCL scl)
{
	if (scl == NULL)
		return (0);
	return (1 + scl_len(scl->next));
}