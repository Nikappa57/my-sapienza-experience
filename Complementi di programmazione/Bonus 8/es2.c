#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"


int sommaSeguitiDaPari(TipoLista l) {
  	TipoLista succ;

	if (estVuota(l) || estVuota(succ = cdr(l)))
      return 0;
  	if (car(succ) % 2 == 0)
      return car(l) + sommaSeguitiDaPari(cdr(l));
  	return sommaSeguitiDaPari(cdr(l));
}


void sommeSeguitiDaPari(TipoLista* liste, int n, TipoLista result){
	for (int i = 0; i < n; i++, result = result->next)
    	result->info = sommaSeguitiDaPari(liste[i]);
}
