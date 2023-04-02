#include "mat.h"

Mat*	mat_sum(Mat *m1, Mat *m2)
{
	Mat	*new;

	
	if ((m1->cols != m2->cols) || (m1->rows != m2->rows))
		return (mat_error());
	new = mat_alloc(m1->rows, m2->cols);
	for (int i = 0; i < m1->rows; i++)
		for (int j = 0; j < m1->cols; j++)
			new->rows_pt[i][j] =
				m1->rows_pt[i][j] + m2->rows_pt[i][j];
	return (new);
}