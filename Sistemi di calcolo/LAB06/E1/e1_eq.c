#include <stdlib.h>
#include "e1.h"

int list_add_first(node_t **arg1, short arg2) {
	node_t **edi = arg1;
	node_t *ebx = *arg1;
	node_t *eax = malloc(sizeof(node_t));
	if (eax == NULL)
		return -1;
	short cx = arg2;
	eax->elem = cx;
	eax->next = ebx;
	*edi = eax;
	return 0;
}