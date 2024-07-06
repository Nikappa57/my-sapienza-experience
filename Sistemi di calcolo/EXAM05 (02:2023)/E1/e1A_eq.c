#include "e1A.h"

int* check_quiz(char** answers, char* solution, int n) {
	char	**edx = answers;
	char	*ebx = solution;
	int		edi = n;
	if (edx == NULL) return NULL;
	if (ebx == NULL) return NULL;
	if (edi <= 0) return NULL;

	int	_eax = edi;
	_eax = _eax * 4;
	int	*eax = malloc(_eax);

	int esi, ebp;
	esi = 0;
L1: if (esi >= edi) goto E1;

	eax[esi] = 0;
	ebp = 0;

L2: if (ebp >= 4) goto E2;
	char	*ecx = edx[esi]; // attenzione: e' un puntatore!
	char	ch = ecx[ebp];
	if (ch == ebx[ebp]) // attenzione: confronto di caratteri!
		eax[esi] += 1;
	ebp++;
	goto L2;
E2:
	esi++;
	goto L1;
E1:
	return eax;
}
