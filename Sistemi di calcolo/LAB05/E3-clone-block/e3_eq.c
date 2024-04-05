#include <stdlib.h>
#include <string.h>

void* clone(const void* src, int n) {
    int edi = n;
    void* eax = malloc(edi);
    if (eax==0)
        return eax;
    void* ebx = eax;
    eax = (void*)src;
    memcpy(ebx, eax, edi);
    eax = ebx;
    return eax;
}
