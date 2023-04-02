# ifndef MATH_H
#define MATH_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#include <unistd.h>

typedef struct
{
	int		rows;
	int		cols;
	float	**rows_pt;
} Mat;

void	mat_random_args(Mat *m);
void	mat_random_args_bin(Mat *m);
Mat		*mat_error(void);
void	mat_print_gol(Mat *m);

Mat		*mat_alloc(int rows, int cols);
void	mat_free(Mat *m);
void	mat_print(Mat *m);
Mat		*mat_clone(Mat *m);
bool	mat_is_symmetric(Mat *m);
void	mat_normalize_rows(Mat *m);
Mat		*mat_normalize_rows_cpy(Mat *m);
Mat*	mat_sum(Mat *m1, Mat *m2);
Mat*	mat_product(Mat *m1, Mat *m2);
Mat*	game_of_life(Mat* mat);

# endif