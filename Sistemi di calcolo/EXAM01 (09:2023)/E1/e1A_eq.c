#include "e1A.h"

void init_matrix(short** m, unsigned n) {
	
	unsigned esi = 0;
L1:	if (esi >= n)
		goto E1;

	unsigned edi = 0; 
L2:	if (edi >= n)
		goto E2;

	short ax = value(esi, edi);
	short *ecx = m[esi];
	ecx[edi] = ax;

	edi++;
	goto L2;
E2:
	esi++;
	goto L1;

E1:
	return ;
}
