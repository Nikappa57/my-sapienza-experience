#include "mat.h"

bool	mat_is_symmetric(Mat *m)
{
	if (m->cols != m->rows)
		return (false);
	for (int i = 0; i < m->rows; i++)
		for (int j = 0; j < m->cols; j++)
			if (m->rows_pt[i][j] != m->rows_pt[j][i])
				return (false);
	return (true);
}