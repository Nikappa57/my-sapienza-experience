#include "aux.h"

int sommaElementi(TipoSCL lis, int i, int j){
  	int tmp;
  
	if (lis == NULL)
      return -1;
 	if (i > 0)
      return sommaElementi(lis->next, i - 1, j - 1);
  	if (i == 0)
    {
      	if ((tmp = sommaElementi(lis, -1, j)) == -1)
          return -1;
    	return lis->info + tmp;
    }
  	if (i == -1 && j > 0)
      return sommaElementi(lis->next, -1, j - 1);
  	if (i == -1 && j == 0)
      return lis->info;
}

void sommatoriaDispari_aux(TipoSCL src, TipoSCL lis, TipoSCL ris, int i){  
  	if (lis == NULL)
      return ;
  	if (i % 2 != 0 && i - 2 > 0)
    	ris->info = sommaElementi(src, i - 2, i);
    else
      	ris->info = lis->info;
  	ris->next = lis->next;
  	sommatoriaDispari_aux(src, lis->next, ris->next, i + 1);
}

void sommatoriaDispari(TipoSCL lis, TipoSCL ris){
  	sommatoriaDispari_aux(lis, lis, ris, 0);
}