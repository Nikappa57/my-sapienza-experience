void interleave(const char* a, const char* b, char* c) {
    const char *eax = a;
    const char *ebx = b;
    char *ecx = c;
L:
    if (*eax == '\0')
        goto S1;
    char dl = *eax;
    *ecx = dl;
    ecx++;
    eax++;

S1:
    if (*ebx == '\0')
        goto S2;
    dl = *ebx;
    *ecx = dl;
    ecx++;
    ebx++;

S2:
    if (*eax != '\0')
        goto L;
    if (*ebx != '\0')
        goto L;
    *ecx = '\0';
}
