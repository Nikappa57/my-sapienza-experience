#include <stdlib.h>

float	max_col(float **mat, int rows, int col)
{
	int max_val = mat[0][col];
  
  	for (int r = 1; r < rows; r++)
    	if (mat[r][col] > max_val)
          max_val = mat[r][col];
 	return (max_val);
}

float * massimi(float **mat, int rows, int cols) {
  
  if ((mat == NULL) || (rows <= 0) || (cols <= 0))
		return (NULL);
    
  float *ret = (float *) malloc(sizeof(float) * cols);
  
  for (int c = 0; c < cols; c++)
  {
  	ret[c] = max_col(mat, rows, c);
  }
  return (ret);
}