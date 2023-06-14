
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

int nodi_per_liv(TipoAlbero a, int l){
	if (estVuoto(a) || l < 0)
      return (0);
    if (l > 0)
    {
    	return nodi_per_liv(sinistro(a), l - 1) + 
      		nodi_per_liv(destro(a), l - 1);
    }
	return (1);
}

int max_albero(TipoAlbero a){
	int max_liv = -1;
  	int max_nodi = 0;
  	int tmp_nodi = -1;
  	
  	for (int i = 0; tmp_nodi != 0; i++)
    {
    	if ((tmp_nodi = nodi_per_liv(a, i)) > max_nodi)
        {
        	max_nodi = tmp_nodi;
          	max_liv = i;
        }
    }
	return max_liv;
}
