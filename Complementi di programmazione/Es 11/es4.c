#include "es11.h"

int	sum(TipoAlbero a)
{
	int sum = 0;
	TipoAlbero s;
	TipoAlbero d;

	if (estVuoto(a))
		return (sum);
	sum += radice(a);
	if (!estVuoto((s = sinistro(a))))
		sum += radice(s);
	if (!estVuoto((d = destro(a))))
		sum += radice(d);
	return (sum);
}

int	conta_dispari(TipoAlbero a)
{
	if (estVuoto(a))
		return (0);
	return ((sum(a) % 2 != 0)
		+ conta_dispari(sinistro(a))
		+ conta_dispari(destro(a)));
}