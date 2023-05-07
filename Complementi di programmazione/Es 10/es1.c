#include "es10.h"

void	stampa_sequenza_inversa(void)
{
	Pila	*stack;
	int 	n;

	stack = pilaVuota();
	while (42)
	{
		scanf("%d", &n);
		if (n < 0)
			break;
		inPila(stack, n);
	}
	while (!estPilaVuota(stack))
		printf("%d ", outPila(stack));
	printf("\n");
}