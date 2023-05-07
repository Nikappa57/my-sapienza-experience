#include "es10.h"

int*	rimuoviMinori(int *arr, int len, int *result_len)
{
	Pila	*stack;
	int		*result;

	if ((arr == NULL) || (len <= 0))
		return (NULL);
	*result_len = len;
	stack = pilaVuota();
	for (int i = 0; i < len; i++)
	{
		while (!estPilaVuota(stack) && arr[i] < primoPila(stack) && (*result_len)--)
			outPila(stack);
		inPila(stack, arr[i]);
	}
	result = (int *) malloc(sizeof(int) * *result_len);
	for (int i = 0; !estPilaVuota(stack) && i < *result_len; i++)
		result[i] = outPila(stack);
	return (result);
}
