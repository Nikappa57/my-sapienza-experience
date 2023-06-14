#include "aux.h"

bool estDivisibile(TipoAlbero a)
{
  	TipoAlbero	s;
  	TipoAlbero	d;

	if (estVuoto(a))
      return false;
  	s = sinistro(a);
  	d = destro(a);
  	if ((!estVuoto(s) && radice(s) != 0
        && radice(a) % radice(s) == 0)
      || (!estVuoto(d) && radice(d) != 0
        && radice(a) % radice(d) == 0))
      return true;
    return false;
}

void nodoDivisibile(TipoAlbero a) {
    if (estVuoto(a))
      return ;
  	if (estDivisibile(a))
      a->info = 1;
  	nodoDivisibile(sinistro(a));
  	nodoDivisibile(destro(a));
}


