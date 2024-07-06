// inserire il C equivalente qui...

int is_suffix(
	const char* s1, const char* s2){

	const char	*eax = s1;
	const char	*ecx = s2;

L1:	if (*eax == 0)
		goto L2;
	eax += 1;
	goto L1;

L2:	if (*ecx == 0)
		goto L3;
	ecx += 1;
	goto L2;

L3:	if (s1 == eax)
		goto E;
	if (s2 == ecx)
		goto E;
	eax -= 1;
	ecx -= 1;
	char edx = *eax;
	if (edx != *ecx)
		goto E;
	goto L3;

E:	char dl = (s1 == eax);
	char al = *eax;
	al = al == *ecx;
	al = al && dl;
	return ((int)al);
}
