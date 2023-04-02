#include "mat.h"

Mat	*mat_product(Mat *m1, Mat *m2)
{
	Mat	*new;
	int	tmp_product;

	new = mat_alloc(m1->rows, m2->cols);
	if (m1->cols != m2->rows)
		return (mat_error());
	for (int r1 = 0; r1 < m1->rows; r1++)
	{
		for (int c2 = 0; c2 < m2->cols; c2++)
		{
			tmp_product = 0;
			for (int i = 0; i < m1->cols; i++)
				tmp_product += m1->rows_pt[r1][i] * m2->rows_pt[i][c2];
			new->rows_pt[r1][c2] = tmp_product;
		}
	}
	return (new);
}