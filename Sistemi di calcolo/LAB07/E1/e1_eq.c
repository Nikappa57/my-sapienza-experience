#include "e1.h"

int binsearch(int *v, int n, int x) {
	int *ebx;
	int edi;

	ebx = v;
	edi = x;
	int eax = 0;
	int ecx = n;

L:	if (eax >= ecx)
		goto E0;
	int edx = eax;
	edx += ecx;
	edx = edx >> 1;
	eax = ebx[edx];
	if (eax == edi)
		goto E1;
	if (eax > edi)
		goto D;
	eax = edx;
	eax += 1;
	goto L;

D:	ecx = edx;
	goto L;

E1:	eax = 1;
	goto E;

E0:	eax = 0;
	goto E;

E:
	return eax;
}
