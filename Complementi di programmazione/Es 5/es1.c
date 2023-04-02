#include "mat.h"

Mat	*mat_alloc(int rows, int cols)
{
	Mat	*new;

	new = (Mat *) malloc(sizeof(Mat));
	new->cols = cols;
	new->rows = rows;
	new->rows_pt = (float **) malloc(sizeof(float *) * rows);
	for (int i = 0; i < rows; i++)
		new->rows_pt[i] = (float *) malloc(sizeof(float) * cols);
	return (new);
}