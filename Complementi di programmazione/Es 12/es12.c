#include "es12.h"

TipoAlbero	*find_min(TipoAlbero *a)
{
	if (estVuoto(*a))
		return NULL;
	if (estVuoto(sinistro(*a)))
		return a;
	return find_min(&((*a)->sinistro));
}

void	binric_rimuovi(TipoAlbero *a, int v)
{
	TipoAlbero	tmp;
	TipoAlbero	*min;

	if (!a || estVuoto(*a))
		return ;
	if (radice(*a) == v)
	{
		if (estFoglia(*a))
		{
			free(*a);
			*a = NULL;
		}
		else if (!estVuoto((tmp = estSingolo(*a))))
		{
			free(*a);
			*a = tmp;
		}
		else
		{
			printf("cerco min\n");
			min = find_min(&((*a)->destro));
			printf("%p\n", min);
			tmp = *min;
			free(*min);
			*min = NULL;
			(*a)->info = radice(tmp);
		}
	}
	else if (v < radice(*a))
		binric_rimuovi(&((*a)->sinistro), v);
	else
		binric_rimuovi(&((*a)->destro), v);
}