#include "e1A.h"

void init_matrix(short** m, unsigned n) {
    unsigned esi, edi;
	short** ebx = m;
	unsigned ebp = n;
	esi=0;
L1:	if (esi >= ebp)
		goto E1;
	edi=0;
L2:	if (edi >= ebp)
		goto E2;
	
	short al = value(esi, edi);
	short *ecx = ebx[esi];
	ecx[edi] = al;

	++edi;
	goto L2;
E2:
	++esi;
	goto L1;
E1:
	return ;
}
