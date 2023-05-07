#include "es10.h"

void	rimuovi_alcuni(Pila *p, const int *rimuovere, int n)
{
	int	i;

	i = 0;
	while (!estPilaVuota(p) && i < n && primoPila(p) == rimuovere[i])
	{
		outPila(p);
		i++;
	}
}