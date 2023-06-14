#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

TipoLista minimiLocali_aux(TipoLista l, T prev) {

  if (estVuota(l) || estVuota(cdr(l)))
    return (listaVuota());
  if (car(l) <= prev && car(l) <= car(cdr(l)))
    return cons(car(l), minimiLocali_aux(cdr(l), car(l)));
  
  return minimiLocali_aux(cdr(l), car(l));
}

TipoLista minimiLocali(TipoLista l) {
  if (estVuota(l))
    return (l);
  return minimiLocali_aux(cdr(l), car(l));
}


int sumList(TipoLista l)
{
	if (estVuota(l))
      return (0);
  return (car(l) + sumList(cdr(l)));
}

int massimaSommaMinimi(TipoLista* liste, int n){
  int max = 0;

  for (int i = 0, tmp; i < n; i++)
  	if ((tmp = sumList(minimiLocali(liste[i]))) > max)
      max = tmp;

  return max;
}
