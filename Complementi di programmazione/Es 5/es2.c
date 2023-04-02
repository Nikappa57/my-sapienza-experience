#include "mat.h"

void	mat_free(Mat *m)
{
	for (int i = 0; i < m->rows; i++)
		free(m->rows_pt[i]);
	free(m->rows_pt);
	free(m);
}