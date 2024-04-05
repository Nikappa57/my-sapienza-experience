int fib(int n)
{
	int eax;
	int esi = n;
	if (esi < 2)
		goto E1;
	esi--;
	int edi = fib(esi);
	esi--;
	eax = fib(esi);
	eax += edi;
	goto E2;
E1: ;
	eax = 1;
E2:
	return eax;
}