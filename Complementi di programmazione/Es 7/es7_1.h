#ifndef ES7_1_H
# define ES7_1_H

#include <stdio.h>
#include <stdlib.h>

typedef float	TipoInfoSCL;

struct ElemSCL {
	TipoInfoSCL info;
	struct ElemSCL *next;
};

typedef struct ElemSCL TipoNodoSCL;
typedef TipoNodoSCL * TipoSCL;

int		scl_len(TipoSCL scl);
float	scl_sum(TipoSCL scl);
float	scl_media(TipoSCL scl);
float	scl_dot(TipoSCL scl1, TipoSCL scl2);
void	scl_duplicate_pos(TipoSCL scl, int pos);
void 	scl_positives(TipoSCL scl, TipoSCL *ris);
TipoSCL scl_positivesf(TipoSCL scl);

#endif