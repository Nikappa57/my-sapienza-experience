
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

bool estFoglia(TipoAlbero a)
{
  	if (estVuoto(a))
      return false;
	return estVuoto(sinistro(a))
    	&& estVuoto(destro(a));
}

void aux(TipoAlbero *a, TipoInfoAlbero prod) {
	if (estVuoto(*a))
      return ;
  	if (estFoglia(*a))
    {
    	if (prod > 0)
        	(*a)->destro = creaAlbBin(
            	prod * radice(*a), NULL, NULL);
      	else
        {
        	free(*a);
          	*a = NULL;
        }
    }
  	else
    {
      	prod *= radice(*a);
    	aux(&((*a)->sinistro), prod);
      	aux(&((*a)->destro), prod);
    }
  
}

void mod_prod_antenati(TipoAlbero *a) {
	aux(a, 1);
}

