#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"


int trovaIndice(int* v, int n, int elem) {
  	int result;

	if (n <= 0)
      return (-1);
  	if (*v == elem)
      return (0);
  	if ((result = trovaIndice(v + 1, n - 1, elem)) == -1)
      return result;
  	return 1 + result;
}

void calcolaIndici_aux(int* v, int n, int* result, int i)
{
  	if (i >= 10)
      return ;
	result[i] =  trovaIndice(v, n, i);
  	calcolaIndici_aux(v, n, result, i + 1);
}

void calcolaIndici(int* v, int n, int* result){
  calcolaIndici_aux(v, n, result, 0);
}
