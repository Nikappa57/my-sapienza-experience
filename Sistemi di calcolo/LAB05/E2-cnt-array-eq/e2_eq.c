int counteq(short* v1, short* v2, int n) {
	int eax = 0;		// cnt
	int ecx = 0;		// i
	short *esi = v1;
	short *edi = v2;
	int edx = n;
L:
	if (ecx >= n)
		goto E;
	short bx = esi[ecx];
	char bl = (bx == edi[ecx]);
	int ebx = (int)bl;
	eax += ebx;
	ecx++;
	goto L;
E:
	return eax;
}