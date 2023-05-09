
#include "aux.h"

void sostituisci_numeri(TipoSCL *list, const char *s)
{
	if ((*list == NULL) || (*s == '\0'))
      return ;
  	if ((*list)->info >= '0' && (*list)->info <= '9')
    {
    	TipoSCL tmp = (TipoSCL) malloc(sizeof(TipoNodoSCL));
      	tmp->next = (*list)->next;
      	tmp->info = *s;
      	*list = tmp;
      	sostituisci_numeri(&((*list)->next), s + 1);
    }
  	else
      sostituisci_numeri(&((*list)->next), s);
}
