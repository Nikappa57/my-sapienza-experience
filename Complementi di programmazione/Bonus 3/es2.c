
#include "aux.h"

TipoLista append_almeno_5(TipoLista list, T elem) {

	if (estVuota(list))
    {
    	if (elem >= 5)
        	return (cons(elem, listaVuota()));
      	return (listaVuota());
    }
	return (cons(car(list), append_almeno_5(cdr(list), elem)));
}

TipoLista inverti_numeri_alti(TipoLista list) {
  TipoLista result;

  for (result = listaVuota(); !estVuota(list); list = cdr(list))
	if (car(list) >= 5)
      result = cons(car(list), result);
  return (result);
}

