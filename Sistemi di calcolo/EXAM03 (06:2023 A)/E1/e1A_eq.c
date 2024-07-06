#include "e1A.h"

void rc4_encrypt(unsigned char *sbox, unsigned char *pt, unsigned char *ct) 
{
    unsigned int ebx = 0, esi = 0;
    unsigned char dh = 0, rnd, al;
	unsigned char *edi = ct;
	unsigned char *ebp = pt;

L:  if (*ebp == 0) goto E;
	esi++;
	esi = esi & 255;
	unsigned char *eax = sbox;
    dh = dh + eax[esi];
    rc4_helper(sbox, esi, dh, &rnd);
	al = rnd;
	al = al ^ *ebp;
    edi[ebx] = al;          // ^ e' l'operatore xor
	ebx++;
	ebp++;
	goto L;
E:
	return ;
}
