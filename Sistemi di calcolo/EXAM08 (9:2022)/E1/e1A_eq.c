#include "e1A.h"

unsigned int* div_vectors(unsigned int* a, unsigned int* b, int n) {
    unsigned int *ecx = NULL;

    if (a == NULL || b == NULL || n == 0)
        goto E;
    int _eax = n;
    _eax *= 4;
    ecx = malloc(_eax);
    int ebx = 0;
L:   if (ebx >= n) goto E;

    unsigned int __eax = a[ebx];
    unsigned int __edx = 0;

    __eax = __eax / b[ebx];
    ecx[ebx] = __eax;  // usare idiv, attenzione a edx! edx : eax / S

    ebx++;
    goto L;
E:
    return ecx;
}
