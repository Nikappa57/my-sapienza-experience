char my_strcmp(const char* s1, const char* s2) {
	const char *c = s1;
	const char *d = s2;
	char a;

L:	a = *c;
	if (a == 0) 
		goto E;
	if (a - *d != 0)
		goto E;
	c++;
	d++;
	goto L;

E:	a -= *d;
	return (a);
}