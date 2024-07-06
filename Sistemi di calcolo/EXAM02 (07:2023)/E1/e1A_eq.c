#include "e1A.h"

unsigned adler32(unsigned char *data, unsigned len) {
	unsigned eax = 0, edx;

	if (data == NULL)
		goto F;

	if (len == 0)
		goto F;

	unsigned k;
	get_adler_constant(&k);
	unsigned ebp = 1, ebx = 0, esi = 0, ecx = k;

L:	if (esi >= len)
		goto E;

	// ebp = (ebp + data[esi]) % k;
	edx = 0;
	eax = data[esi];
	eax += ebp;
	edx = eax % ecx;
	ebp = edx;

	// ebx = (ebx + ebp) % k;
	edx = 0;
	eax = ebx;
	eax += ebp;
	edx = eax % ecx;
	ebx = edx;

	esi++;
	goto L;

E:	
	eax = ebx;
	eax = eax << 16;
	eax = eax | ebp;
	return eax;
	// return (ebx << 16) | ebp;

F:	return eax;
}
