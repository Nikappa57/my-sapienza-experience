#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "aux.h"

double	sub_m(Mat *m, int c, int r)
{
	double sum = 0;
  	
  	for (int i = c; i < c + m->rows / 2; i++)
      for (int j = r; j < r + m->cols / 2; j++)
        sum += m->mat[i][j];
  	return sum;
}

Mat* massima_sottomatrice(Mat *m){
  Mat	*result;
  double max_m = 0;
  double tmp_m;
  int max_r = 0;
  int max_c = 0;
  
  for (int r = 0; r <= m->cols / 2; r++)
  {
  	for (int c = 0; c <= m->rows / 2; c++)
    {
    	if ((tmp_m = sub_m(m, r, c)) > max_m)
        {
        	max_m = tmp_m;
          max_r = r;
          max_c = c;
        }
    }
  }
  result = mat_alloc(m->rows / 2, m->cols / 2);
  for (int r = 0; r < m->rows / 2 ; r++)
      for (int c = 0; c < m->cols / 2; c++)
        result->mat[r][c] = m->mat[max_r + r][max_c + c]; 
  
  return (result);
}
