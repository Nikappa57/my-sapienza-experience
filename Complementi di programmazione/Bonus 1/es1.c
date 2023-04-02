static double	sum_rows(double *arr, int len)
{
	double	sum;

	sum = 0;
	for (int i = 0; i < len; i++)
		sum += arr[i];
    return (sum);
}

static double	sum_cols(double **mat, int col, int rows)
{
	double	sum;

	sum = 0;
	for (int i = 0; i < rows; i++)
		sum += mat[i][col];
    return (sum);
}

void	max_row_col(double **input, int rows, int cols, int* max_row, int* max_col) {
	double	max_row_sum;
	double	max_col_sum;
	double	tmp_sum;
  
	max_row_sum = 0;
  	max_col_sum = 0;
	for (int i = 0; i < rows; i++)
    {
      if ((tmp_sum = sum_rows(input[i], cols)) > max_row_sum)
      {
      	max_row_sum = tmp_sum;
        *max_row = i;
      }
    }
	for (int i = 0; i < cols; i++)
    {
      if ((tmp_sum = sum_cols(input, i, rows)) > max_col_sum)
      {
      	max_col_sum = tmp_sum;
        *max_col = i;
      }
    }
}
