#include "e1B.h"

int crc32b(char *bytes, int n) {
    int ebx = ~0;
    int esi = n;
    char *edi = bytes;
    int eax;

L:  
    if (esi == 0)
        goto E;
    esi--;
    eax = *edi; // promozione
    edi++;
    eax = eax ^ ebx;
    eax = eax & 0xFF;
    int value;
    get_constant(&value, eax);
    int ecx = value;
    ebx = ebx >> 8;
    ebx = ebx ^ ecx;
    goto L;

E:
    eax = ~0;
    eax = eax ^ ebx;
    return eax;
}

