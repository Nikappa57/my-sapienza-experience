#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "aux.h"

int* piupari_menodispari(Mat *m){
  int	*result;
  
  result = (int *) malloc(sizeof(int) * m->rows);
  for (int r = 0; r < m->rows; r++)
  {
    result[r] = 0;
  	for (int c = 0; c < m->cols; c++)
    {
    	if (c % 2 == 0)
          result[r] += m->mat[r][c];
      	else
          result[r] -= m->mat[r][c];
    }
  }
  return (result);
}
