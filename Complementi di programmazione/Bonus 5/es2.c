
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"


int somma_livello(TipoAlbero a, int l)
{
	if (estVuoto(a) || (l < 0))
      return (0);
  	if (l > 0)
      return somma_livello(sinistro(a), l - 1) +
      	somma_livello(destro(a), l - 1);
    return radice(a);
}

int crescente(TipoAlbero a) {
  	int tmp;
	int somma = somma_livello(a, 0);
	
  	for (int i = 1; somma != 0; i++)
    {
    	tmp = somma_livello(a, i);
        if (tmp == 0)
          break;
      	if (tmp < somma)
          return i;
      	somma = tmp;
          
    }
	return -1;
}
