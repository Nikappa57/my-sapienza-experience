
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

TipoInfoAlbero	max(TipoInfoAlbero a, TipoInfoAlbero b)
{
	return a >= b ? a : b;
}

bool estFoglia(TipoAlbero a)
{
	if (estVuoto(a))
      return false;
  	return (estVuoto(sinistro(a))
            && estVuoto(destro(a)));
}

TipoInfoAlbero	max_somma(TipoAlbero a)
{
	if (estVuoto(a))
      return 0;
  	if (estFoglia(a))
      return radice(a);
  	if (estVuoto(sinistro(a)))
      return radice(a) + max_somma(destro(a));
  	if (estVuoto(destro(a)))
      return radice(a) + max_somma(sinistro(a));
  	return radice(a)
      	+ max(
      		max_somma(sinistro(a)),
      		max_somma(destro(a)));
}

TipoAlbero figlio_lontano(TipoAlbero a) {

  	if (estVuoto(a))
      return albBinVuoto();
  	return creaAlbBin(max_somma(a),
                      figlio_lontano(sinistro(a)),
                      figlio_lontano(destro(a)));
}
