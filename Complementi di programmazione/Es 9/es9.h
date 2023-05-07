#ifndef ES9_H
# define ES9_H

#include "lista.h"

void	print(TipoLista list);
TipoLista	append(T val, TipoLista list);

TipoLista	init(T *vec, int len);
TipoLista	init_r(T *vec, int len);
TipoLista	doubledCopy(TipoLista list);
TipoLista	doubledCopy_r(TipoLista list);
TipoLista	multipleSublist(TipoLista list, unsigned int m);
TipoLista	multipleSublist_r(TipoLista list, unsigned int m);
TipoLista	subList(TipoLista list, int start, int end);
TipoLista	subList_r(TipoLista list, int start, int end);
TipoLista	interleave(TipoLista l1, TipoLista l2);


#endif