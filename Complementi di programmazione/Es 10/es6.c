#include "es10.h"

void	stampa_sequenza(void)
{
	int	n;
	Coda *queue;

	queue = codaVuota();
	while (42)
	{
		scanf("%d", &n);
		if (n < 0)
			break;
		inCoda(queue, n);
	}
	while (!estCodaVuota(queue))
		printf("%d ", outCoda(queue));
	printf("\n");
}