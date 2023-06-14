#include "aux.h"

TipoInfoAlbero max(TipoInfoAlbero a, TipoInfoAlbero b)
{
	return a >= b ? a : b;
}

TipoInfoAlbero sommaMassimaPercorso(TipoAlbero a){
	if (estVuoto(a))
      return (0);
  	return radice(a) + max(
      	sommaMassimaPercorso(sinistro(a)),
    	sommaMassimaPercorso(destro(a)));
}
