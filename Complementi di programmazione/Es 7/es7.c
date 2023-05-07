#include "es7_2.h"

void	sclstring_print(TipoSCL s)
{
	if (s == NULL)
		return ;
	printf("%c", s->info);
	sclstring_print(s->next);
}