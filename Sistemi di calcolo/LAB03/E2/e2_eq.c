unsigned fib(unsigned n) {
	unsigned a = 1;
	unsigned c = 0;
	unsigned d = n;

	if (d != 0)
		goto E;

	a = 0;
	return a;

E:
	if (d - 1 != 0)
		goto L;
	return a;

L:
	if (d - 1 <= 0)
		goto J;
	c += a;
	c += a;
	a -= c;
	a *= -1;
	c -= a;
	d--;
	goto L;

J:
	return a;
}
