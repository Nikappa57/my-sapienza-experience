#include "mat.h"

static int	row_module(float *row, int cols)
{
	float	sum_square;

	sum_square = 0;
	for (int i = 0; i < cols; i++)
		sum_square += pow(row[i], 2);
	return (sqrt(sum_square));
}

void	mat_normalize_rows(Mat *m)
{
	float	module;

	for (int i = 0; i < m->rows; i++)
	{
		module = row_module(m->rows_pt[i], m->cols);
		for (int j = 0; j < m->cols; j++)
			m->rows_pt[i][j] /= module;
	}
}

Mat	*mat_normalize_rows_cpy(Mat *m)
{
	Mat		*new;
	float	module;

	new = mat_alloc(m->rows, m->cols);
	for (int i = 0; i < m->rows; i++)
	{
		module = row_module(m->rows_pt[i], m->cols);
		for (int j = 0; j < m->cols; j++)
			new->rows_pt[i][j] =
				m->rows_pt[i][j] / module;
	}
	return (new);
}