
#include "aux.h"

bool is_nbr(char c)
{
	if (c >= '0' && c <= '9')
      return (true);
  	return (false);
}

void sostituisci_numeri(TipoSCL *list, const char *s) {
  	TipoSCL tmp;

	if (!list || !(*list) || !(*s))
      return ;
  	if (is_nbr((*list)->info))
    {
    	tmp = (TipoSCL) malloc(sizeof(TipoNodoSCL));
      	tmp->info = *s++;
        tmp->next = (*list)->next;
      	free(*list);
      	*list = tmp;
    }
  sostituisci_numeri(&((*list)->next), s);
}
