#include "es9.h"

TipoLista	append(T val, TipoLista list)
{
	if (estVuota(list))
		return (cons(val, list));
	return (cons(car(list), append(val, cdr(list))));
}

void	print(TipoLista list)
{
	if (estVuota(list))
	{
		printf("\n");
		return ;
	}
	printf("%d ", car(list));
	print(cdr(list));
}
