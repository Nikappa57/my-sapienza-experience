#include "es7_1.h"

float	scl_media(TipoSCL scl)
{
	return (scl_sum(scl) / scl_len(scl));
}