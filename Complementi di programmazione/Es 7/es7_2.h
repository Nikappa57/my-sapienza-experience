#ifndef ES7_2_H
# define ES7_2_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char	TipoInfoSCL;

struct ElemSCL {
	TipoInfoSCL info;
	struct ElemSCL *next;
};

typedef struct ElemSCL TipoNodoSCL;
typedef TipoNodoSCL * TipoSCL;

void	sclstring_print(TipoSCL s);
void	sclstring_create(const char *s, TipoSCL *ris);
TipoSCL	sclstring_createf(const char *s);
#endif