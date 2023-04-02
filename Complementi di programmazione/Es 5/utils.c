#include "mat.h"

void	mat_random_args(Mat *m)
{
	for (int i = 0; i < m->rows; i++)
		for (int j = 0; j < m->cols; j++)
			m->rows_pt[i][j] = (float)rand() / (float)(RAND_MAX / 9);
}

void	mat_random_args_bin(Mat *m)
{
	for (int i = 0; i < m->rows; i++)
		for (int j = 0; j < m->cols; j++)
			m->rows_pt[i][j] = (float)(rand() % 2);
}

void	mat_print_gol(Mat *m)
{
	if (!m)
		return ;
	for (int i = 0; i < m->rows; i++)
	{
		for (int j = 0; j < m->cols; j++)
		{
			if (m->rows_pt[i][j])
				printf("*");
			else
				printf("-");
		}
		printf("\n");
	}
	printf("\n\n");
}

Mat	*mat_error(void)
{
	printf("Error\n");
	return (NULL);
}