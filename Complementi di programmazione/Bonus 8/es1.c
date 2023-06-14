#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"


int max(int a, int b)
{
	return a >= b ? a : b;
}

int maxMinoreSuccessivo(TipoLista l) {
	TipoLista	succ;

	if (estVuota(l))
      return (0);
  	succ = cdr(l);
  	if (estVuota(succ))
      return (0);
  	if (car(l) < car(succ))
      return max(car(l), maxMinoreSuccessivo(succ));
  	return maxMinoreSuccessivo(succ);
}


void massimiMinoriSuccessivo(TipoLista* liste, int n, TipoLista result){
	for (int i = 0; i < n; i++, result = result->next)
    	result->info = maxMinoreSuccessivo(liste[i]);
}
