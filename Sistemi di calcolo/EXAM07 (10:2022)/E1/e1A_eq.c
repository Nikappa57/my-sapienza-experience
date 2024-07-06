#include "e1A.h"

char* str_to_upper(const char* s) {
    char *esi = NULL;
    const char* _eax = s;
    if (_eax == NULL) return NULL;
    // strdup e' una funzione della libreria C!

    char* eax = strdup(_eax);
    esi = eax;

    char* edi = esi;
L:    if (*edi == '\0')
        goto E;
        // toupper e' una funzione della libreria C!
    char al = toupper(*edi); 
    *edi = al;
    edi++;
    goto L;
E:
    return esi;
}
