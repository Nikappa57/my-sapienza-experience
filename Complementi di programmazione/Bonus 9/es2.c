#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

int pow(int b, int exp)
{
	if (exp == 0)
      return (1);
  	return b * pow(b, exp - 1);
}

TipoLista calcolaRappresentazioneDecimale(TipoLista l) {
	TipoLista result;
  	int nbr = 0;
  
  	for (int i = 0; !estVuota(l); l = cdr(l), i++)
    	nbr += car(l) * pow(2, i);      
  	for (result = listaVuota(); nbr > 0; nbr /= 10)
    	result = cons(nbr % 10, result);
  return result;
}


