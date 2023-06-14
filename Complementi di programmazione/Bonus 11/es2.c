
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

bool estFoglia(TipoAlbero a)
{
	if (estVuoto(a))
      return (false);
  	return (estVuoto(sinistro(a)) && estVuoto(destro(a)));
}

int max(int a, int b)
{
	return a >= b ? a : b;
}

int min(int a, int b)
{
	return a <= b ? a : b;
}

TipoAlbero aux(const TipoAlbero a, int a_min, int a_max) {
	TipoAlbero	result;

  	if (estVuoto(a) || (estFoglia(a) && (a_max - a_min) % 2 != 0))
      return (NULL);
  	result = creaAlbBin(
    		radice(a),
            aux(sinistro(a),
            	min(radice(a), a_min),
            	max(radice(a), a_max)),
            aux(destro(a),
            	min(radice(a), a_min),
                max(radice(a), a_max)));
  	if (estFoglia(a))
    	result->sinistro = creaAlbBin(a_min + radice(a), NULL, NULL);
  	return result;
}

TipoAlbero mod_diff_antenati(const TipoAlbero a) {
  	if (estVuoto(a))
      return NULL;
  	if (estFoglia(a))
		return aux(a, 0, 0);
  	return creaAlbBin(radice(a),
                      aux(sinistro(a), radice(a), radice(a)),
                      aux(destro(a), radice(a), radice(a)));
}
