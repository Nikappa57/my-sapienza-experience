int find(int* v, int n, int x) {
    int a = 0;
	int *c = v;
	int d = x;
    
L:	if (a - n >= 0)
		goto E0;
	if (*(c + a) == d)
		goto E1;
	a++;
	goto L
E0:
	a = 0;
    return a;
E1:	
	a = 1;
	return a;
}