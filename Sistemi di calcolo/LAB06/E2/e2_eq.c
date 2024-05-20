#include <stdlib.h>
#include "e2.h"

int list_equal(const node_t *l1, const node_t *l2)
{
	const node_t *ecx = l1;
	const node_t *edx = l2;
	int eax;

L:	if (ecx == NULL)
		goto E;
	if (edx == NULL)
		goto E;
	eax = ecx->elem;
	if (eax != edx->elem)
		goto D;
	ecx = ecx->next;
	edx = edx->next;
	goto L;
E:	
	int ah = ecx == NULL;
	int	al = edx == NULL;
	eax = ah && al;
	return eax;
D:	
	eax = 0;
	return eax;
}