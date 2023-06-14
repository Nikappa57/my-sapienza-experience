
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

bool estFoglia(TipoAlbero a)
{
  if (!a)
    return (false);
  return (!(a->sinistro) && !(a->destro));
}

void taglia_livello(TipoAlbero *a, int livello)
{
  TipoAlbero	s;
  TipoAlbero	d;

  if (!a || !(*a) || (livello - 1 < 0))
    return ;
  s = (*a)->sinistro;
  d = (*a)->destro;
  if (livello - 1 > 0)
  {
  	taglia_livello(&s, livello - 1);
    taglia_livello(&d, livello - 1);
    return ;
  }
  if (estFoglia(s))
  {
    (*a)->info += s->info;
    (*a)->sinistro = NULL;
    free(s);
  }
  if (estFoglia(d))
  {
    (*a)->info += d->info;
    (*a)->destro = NULL;
    free(d);
  }
}
