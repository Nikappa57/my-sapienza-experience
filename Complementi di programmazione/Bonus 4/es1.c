
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

bool estFoglia(TipoAlbero a)
{
	if (!a)
      return false;
  	return (!(a->sinistro) && !(a->destro));
}

void taglia_foglie(TipoAlbero *a) {
	
   if (!(*a))
      return ;
   taglia_foglie(&((*a)->sinistro));
   taglia_foglie(&((*a)->destro));
   if (estFoglia((*a)->sinistro) && !((*a)->destro))
   {
  		(*a)->info += (*a)->sinistro->info;
  		free((*a)->sinistro);
     	(*a)->sinistro = NULL;
  	}
  	else if (estFoglia((*a)->destro) && !((*a)->sinistro))
    {
    	(*a)->info += (*a)->destro->info;
      	free((*a)->destro);
      	(*a)->destro = NULL;
    }
}
