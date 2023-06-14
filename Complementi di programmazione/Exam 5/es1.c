#include "e5.h"

int	conditionalSum(Mat *src, int flag)
{
	int	sum = 0;

	for (int r = 0; r < src->rows; r++)
	{
		for (int c = 0; c < src->cols; c++)
		{
			if (flag == 0 && c % 2 != 0)
				sum += -1 * src->mat[r][c];
			else if (flag == 1 && r % 2 != 0)
				sum += -1 * src->mat[r][c];
			else
				sum += src->mat[r][c];
		}
	}
	return sum;
}