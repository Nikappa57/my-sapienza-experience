#include "e1A.h"

int* strings_are_upper(const char** array, int n) {
	const char** esi = array;

	if (esi == NULL) return NULL;
	if (n <= 0) return NULL;
	int* ebp = malloc(sizeof(int) * n);
	int ebx = 0;
L1: if (ebx >= n) 
		goto E1;

	const char* edi = esi[ebx];
	ebp[ebx] = 1;

L2: if (*edi == 0)
		goto E2;

	// isupper e' una funzione della libc (vedere: man isupper)
	char eax = *edi;
	int eax = isupper(eax);

	if (eax != 0) 
		goto S;
	
	ebp[ebx] = 0;
	goto E2;
S:
	edi += 1;
	goto L2;
	
E2:
	ebx++;
	goto L1;
E1:
	return ebp;
}
