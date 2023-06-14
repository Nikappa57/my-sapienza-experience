#include "aux.h"

void rimuoviCircolare(Coda* c, const int i){
  	if (estCodaVuota(c))
      return ;
	for (int j = 0; j < i; j++)
      inCoda(c, outCoda(c));
  	outCoda(c);
}
