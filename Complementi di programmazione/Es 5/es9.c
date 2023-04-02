#include "mat.h"

static int	count_live_neighbours(Mat* mat, int r, int c)
{
	int	live;

	live = 0;
	if (r > 0 && mat->rows_pt[r - 1][c])
		live += 1;
	if (r + 1 < mat->rows && mat->rows_pt[r + 1][c])
		live += 1;
	if (c > 0 && mat->rows_pt[r][c - 1])
		live += 1;
	if (c + 1 < mat->cols && mat->rows_pt[r][c + 1])
		live += 1;
	return (live);
}

Mat*	game_of_life(Mat* mat)
{
	Mat	*new;
	int	live;

	new = mat_alloc(mat->rows, mat->cols);
	for (int i = 0; i < mat->rows; i++)
	{
		for (int j = 0; j < mat->cols; j++)
		{
			live = count_live_neighbours(mat, i, j);
			if (mat->rows_pt[i][j] && ((live < 2) || (live > 3)))
				new->rows_pt[i][j] = 0;
			else if (!(mat->rows_pt[i][j]) && live == 3)
				new->rows_pt[i][j] = 1;
			else
				new->rows_pt[i][j] = mat->rows_pt[i][j];
		}
	}
	return (new);
}