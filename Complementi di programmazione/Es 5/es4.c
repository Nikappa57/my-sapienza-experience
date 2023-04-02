#include "mat.h"

Mat	*mat_clone(Mat *m)
{
	Mat	*new;

	new = mat_alloc(m->rows, m->cols);
	for (int i = 0; i < m->rows; i++)
		for (int j = 0; j < m->cols; j++)
			new->rows_pt[i][j] = m->rows_pt[i][j];
	return (new);
}
