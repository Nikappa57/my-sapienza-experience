#include "e2.h"

int crc32b(char *bytes, int n) {
	int ebx = 0;
	ebx = ~ebx;
	int edi = ebx;
	int esi = n;

L:	if (esi == 0)
		goto E;
	esi--;
	char *eax_ = bytes;
	int eax = *eax_;
	bytes++;
	int edx = edi;
	edx = edx ^ eax;
	edx = edx & 0xFF;
	int value;
	get_constant(&value, edx);
	eax = edi;
	eax = eax >> 8;
	edi = value ^ eax;
	goto L;

E:	;
	int _eax = edi;
	_eax = _eax ^ ebx;
	return (_eax);
}