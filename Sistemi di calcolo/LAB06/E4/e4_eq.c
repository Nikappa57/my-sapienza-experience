#include "e4.h"

int lcm(int x, int y) {
	int ebx = x;
	int edi = y;
	int ecx = edi;
	int eax;
	int edx;

    if (ebx > ecx)
        ecx = ebx;
L:
	eax = ecx;
	edx = 0;
    if (eax % ebx != 0)
		goto E;
	edx = 0;
	eax = ecx;
	if (eax % edi != 0)
		goto E;
    return ecx;

E:	ecx++;
	goto L;
}
