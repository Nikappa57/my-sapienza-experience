
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

int somma_massima(int somma_s, int pari_s, int somma_d, int pari_d, int *pari_tot)
{
	if (pari_s > pari_d)
      return (*pari_tot += pari_s, somma_s);
  	if (pari_s < pari_d)
      return (*pari_tot += pari_d, somma_d);
  	if (somma_s >= somma_d)
      return (*pari_tot += pari_s, somma_s);
    return (*pari_tot += pari_d, somma_d);
}

int cammino_pari_helper(TipoAlbero a, int *pari) {
	int pari_s = 0;
  	int pari_d = 0;
  	int somma_s;
  	int somma_d;

  	if (estVuoto(a))
      return 0;
  	*pari += (radice(a) % 2 == 0);
  	somma_s = radice(a) + cammino_pari_helper(sinistro(a), &pari_s);
  	somma_d = radice(a) + cammino_pari_helper(destro(a), &pari_d);
	
  
	return somma_massima(somma_s, pari_s, somma_d, pari_d, pari);
}

int cammino_pari(TipoAlbero a) {
	if (estVuoto(a))
      return (0);
  	int pari = 0;
  	return cammino_pari_helper(a, &pari);
}

