#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"


TipoLista iniziali(TipoLista list, int k) {

	if (estVuota(list) || (k <= 0))
      return listaVuota();
  	return cons(car(list), iniziali(cdr(list), k - 1));
}


TipoLista * liste_iniziali(TipoLista list) {
	
  int	len = 0;
  TipoLista tmp;
  
  tmp = list;
  while (!estVuota(tmp))
  {
  	len++;
    tmp = cdr(tmp);
  }
  
  TipoLista *arr = (TipoLista *) malloc(sizeof(TipoLista) * len);

  for (int i = 0; i < len; i++)
  {
  	arr[i] = iniziali(list, i + 1);
  }
  return arr;
}
