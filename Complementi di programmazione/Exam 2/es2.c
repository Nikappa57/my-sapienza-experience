#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

int	posizioni_alternanza_aux(TipoLista l, char c1, char c2)
{
  	if (estVuota(l))
      return (0);
	if (!c1 && !c2)
      return 1 + posizioni_alternanza_aux(cdr(l), c1, car(l));
  	if (!c1)
      return 1 + posizioni_alternanza_aux(cdr(l), c2, car(l));
  	if (c1 != car(l))
      return (0);
  	return 1 + posizioni_alternanza_aux(cdr(l), c2, c1);
  	
}

int posizioni_alternanza(TipoLista l) {

	return posizioni_alternanza_aux(l, '\0', '\0');
}

int	listLen(TipoLista l)
{
	if (estVuota(l))
      return (0);
  	return 1 + listLen(cdr(l));
}

char *prefisso_alternante(TipoLista *liste, int n) {
	TipoLista	l_max = listaVuota();
  	int			p_tmp;
  	int			p_max = 0;
  	int			len;
  	char		*result;

  	if (liste == NULL || n <= 0)
      return NULL;
	for (int i = 0; i < n; i++)
    {
    	p_tmp = posizioni_alternanza(liste[i]);
      	if (p_tmp > p_max)
        {
        	p_max = p_tmp;
          	l_max = liste[i];
        }
    }
  	while (p_max-- > 0 && !estVuota(l_max))
      l_max = cdr(l_max);
    len = listLen(l_max);
  	result = (char *) malloc(sizeof(char) * len + 1);
  	for (int i = 0; i < len; i++, l_max = cdr(l_max))
    	result[i] = car(l_max);
  	result[len] = '\0';
  	return result;
}
