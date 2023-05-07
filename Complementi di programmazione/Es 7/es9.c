#include "es7_2.h"

bool	sclstring_equals(TipoSCL scl, const char *s)
{
	if (scl == NULL && ((s == NULL) || (*s == '\0')))
		return (true);
	if ((scl == NULL) || ((s == NULL) || (*s == '\0')))
		return (false); 
	if (scl->info != *s)
		return (false);
	return (sclstring_equals(scl->next, s + 1));
}