#include "aux.h"

void bombardamentoNavale(Mat *src, int r, int c){
  if (!src || !(src->row_ptrs))
    return ;
  if (r < src->rows && r >= 0 && c < src->cols && c >= 0
      && src->row_ptrs[r][c] == 1)
  {
  	src->row_ptrs[r][c] = 0;
    bombardamentoNavale(src, r + 1, c);
  	bombardamentoNavale(src, r - 1, c);
    bombardamentoNavale(src, r, c + 1);
    bombardamentoNavale(src, r, c - 1);
  }
}

