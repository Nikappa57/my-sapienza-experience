int count_digits(const char *s) {
	int eax = 0;
	const char *ecx = s;

L:	char  dl = *ecx;
	if (dl == 0)
		goto E;
	if (dl < 48)
		goto P;
	if (dl > 57)
		goto P;
	eax++;

P:	ecx++;
	goto L;

E:	return (eax);
}