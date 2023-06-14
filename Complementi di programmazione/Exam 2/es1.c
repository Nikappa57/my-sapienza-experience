#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "aux.h"

double	media_colonna(Mat *m, int col)
{
  	int	somma = 0;
 
	for (int r = 0; r < m->rows; r++)
    	somma += m->mat[r][col];
 	return (somma / m->rows);
      
}

int* controlla_colonne(Mat *m, double w, double v){
	int	*result;
  	int media;
  
  	result = (int *) malloc(sizeof(int) * m->cols);
  	for (int c = 0; c < m->cols; c++)
    {
      media = media_colonna(m, c);
      if (media >= w && media <= v)
        result[c] = 1;
      else
        result[c] = 0;
    }
  	return result;
}
