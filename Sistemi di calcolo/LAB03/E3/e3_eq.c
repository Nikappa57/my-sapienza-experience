int comp(const void* xv, const void* yv) {
	int* x = (int*)xv;
	int* y = (int*)yv;

	int a = *x;
	a -= *y;
	return a;
}
