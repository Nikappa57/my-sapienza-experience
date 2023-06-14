#ifndef E5_H
# define E5_H

#include <time.h>

#include "albero_binario.h"
#include "mat.h"
#include "lista.h"

TipoAlbero	prodottoVicini(TipoAlbero a);
TipoLista	inFondo(TipoLista l);
TipoLista	invertiInParte(TipoLista l, int inizio);
int			conditionalSum(Mat *src, int flag);
#endif