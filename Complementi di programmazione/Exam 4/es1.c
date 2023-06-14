#include "aux.h"


void applicaFiltro(Mat *src, Mat * filtro, int riga, int colonna){
  for (int r_f = 0; r_f < filtro->rows; r_f++)
  	for (int c_f = 0; c_f < filtro->cols; c_f++)
    	if (riga + r_f < src->rows && colonna + c_f < src->cols)
          src->row_ptrs[riga + r_f][colonna + c_f] *=
          	filtro->row_ptrs[r_f][c_f];
}

