
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

int	numero_nodi(TipoAlbero a)
{
	if (estVuoto(a))
      return 0;
  	return 1
      + numero_nodi(sinistro(a))
      + numero_nodi(destro(a));
}

int max(int a, int b)
{
	return a >= b ? a : b;
}

void aux(TipoAlbero a, int m) {
  	int	r;
  
	if (estVuoto(a))
      return ;
  	r = radice(a);
  	a->info = numero_nodi(
      (m % 2 == 0)
      	? destro(a)
      	: sinistro(a));
    m = max(r, m);
  	aux(sinistro(a), m);
  	aux(destro(a), m);
}

void scegli_discendenti(TipoAlbero a) {
	aux(a, -10);
}

