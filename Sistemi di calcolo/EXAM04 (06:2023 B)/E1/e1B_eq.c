#include "e1B.h"

void rc4_encrypt_rev(unsigned char *sbox, unsigned char *pt, unsigned char *ct)
{
    unsigned int esi = 0;
	unsigned char bh = 0;

	unsigned char *edi = ct;

	unsigned char *ebp = pt;
	int eax = strlen(ebp);
	eax--;
	ebp += eax;

L:  if (ebp < pt) goto E;
	
	esi++;
	esi = esi & 255;
	unsigned char *_eax = sbox;
    bh += _eax[esi];
	unsigned char al = rc4_helper(_eax, esi, bh);
	al = al ^ *ebp;
	*edi = al;
    *ebp--;
    edi++;
	goto L;
E:
	return ;
}
