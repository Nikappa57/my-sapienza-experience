#include "mat.h"

void	mat_print(Mat *m)
{
	if (!m)
		return ;
	for (int i = 0; i < m->rows; i++)
	{
		for (int j = 0; j < m->cols; j++)
			printf("%.2f ", m->rows_pt[i][j]);
		printf("\n");
	}
	printf("\n");
}