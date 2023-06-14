
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

int max(int a, int b)
{
	return a >= b ? a : b;
}

int somma_sottoalbero(TipoAlbero a)
{
	if (estVuoto(a))
      return (0);
  	return radice(a)
      	+ somma_sottoalbero(sinistro(a))
      	+ somma_sottoalbero(destro(a));
}

void aux(TipoAlbero a, int somma) {
  	int	r;

  	if (estVuoto(a))
      return ;
  	r = radice(a);
	if (somma < max(
      	somma_sottoalbero(sinistro(a)), 
      	somma_sottoalbero(destro(a))))
      a->info = 1;
  	else
      a->info = 0;
  	somma += r;
  	aux(sinistro(a), somma);
  	aux(destro(a), somma);
}


void confronto_antenati_successori(TipoAlbero a) {
	
	aux(a, 0);
}
