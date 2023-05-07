#include "es7_2.h"

void	sclstring_create(const char *s, TipoSCL *ris)
{
	if ((s == NULL) || (*s == '\0'))
	{
		ris = NULL;
		return ;
	}
	*ris = (TipoSCL) malloc(sizeof(TipoNodoSCL));
	(*ris)->info = *s;
	sclstring_create(s + 1, &((*ris)->next));
}

TipoSCL	sclstring_createf(const char *s)
{
	TipoSCL ris = NULL;
	sclstring_create(s, &ris);
	return (ris);
}