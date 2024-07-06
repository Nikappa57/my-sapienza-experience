#include "e1A.h"

int suffix(const char* a, const char* b) {
	const char *ebx = b;
	const char *esi = a;

	int edi = strlen(esi);
	int eax = strlen(ebx);

	if (eax > edi)
		goto E0;

	int ecx = edi;
	ecx = ecx - eax;

L:  if (ecx >= edi)
		goto E;
	
	char dh = *ebx;
	ebx++;

	if (esi[ecx] != dh)
		goto E0;

	ecx++;
	goto L;

E:	return 1;
E0:	return 0;
}
