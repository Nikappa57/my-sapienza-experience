#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "aux.h"

int* somma_negativi(Mat *m){
  int	*result;
  
  result = (int *) malloc(sizeof(int) * m->rows);
  for (int c = 0; c < m->cols; c++)
  {
  	result[c] = 0;
    for (int r = 0; r < m->rows; r++)
      if (m->mat[r][c] < 0)
        result[c] += m->mat[r][c];
  }
  return (result);
}
