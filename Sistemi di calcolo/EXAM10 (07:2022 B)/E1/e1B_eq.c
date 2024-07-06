#include "e1B.h"

int count_matching_vars(char** vars, char* pattern) {
    int ebx = -1;
    char **esi = vars;

    if (esi == NULL || pattern == NULL)
        return -1;

    ebx = 0;

L:    if (*esi == NULL)
        goto E;

    char* eax = getenv(*esi);
    if (eax == NULL)
        goto S;

    eax = strstr(eax, pattern);
    if (eax == NULL)
        goto S;

    ebx += 1;

S:  esi++;
    goto L;
E:
    return ebx;
}
