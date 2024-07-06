#include "e1A.h"

int* count_vars(char** vars, int n) {
    char **edi = vars;
    if (edi == NULL || n <= 0)
        return NULL;

    int* ebx = malloc(sizeof(int) * n);
    int esi = 0;

L:  if ( esi >= n) goto E;
    
    if (getenv(edi[esi]) != NULL)
        ebx[esi] = 1;
    else
        ebx[esi] = 0;
    esi++;
    goto L;
E:
    return ebx;
}
