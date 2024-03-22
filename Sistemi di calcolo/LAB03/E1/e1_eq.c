int min(int x, int y, int z) {
	int a = x;
	if (a - y >= 0)
		goto L;

	if (a - z >= 0)
		goto E;

	return a;

E:
	a = z;
	return a;

L:
	a = y;
	if (a - z >= 0)
		goto I;
	return a;
I:
	a = z;
	return a;
}