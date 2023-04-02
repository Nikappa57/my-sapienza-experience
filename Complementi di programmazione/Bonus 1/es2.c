#include <stdlib.h>

int	find_max_col(float **mat, int rows, int col)
{
	int	max_index = 0;
	
	for (int i = 0; i < rows; i++)
    	if (mat[i][col] > mat[max_index][col])
          max_index = i;
    return (max_index);
}

float	*arr_alloc(int len)
{
	float	*arr;
  
 	if (!(arr = (float *) malloc(sizeof(float) * len)))
    	return (NULL);
	return (arr);
}

float * massimi(float **mat, int rows, int cols) {
	float	*max;
  
	if (!(max = arr_alloc(cols)))
      return (NULL);
	for (int i = 0; i < cols; i++)
      max[i] = mat[find_max_col(mat, rows, i)][i];
  	return (max);
	
}