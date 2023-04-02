#include <stdio.h>

int	main(void)
{
	int a = 10;
	int b = -1;
	int c;
	int *pa, *pb, *pc;
	// Assegnare i puntatori (da completare)
	pa = &a;
	pb = &b;
	pc = &c;
	// Inserire codice qui (che contenga solo pa, pb, pc)
	*pc = *pa + *pb;
	printf("%d == a + b\n", c);

}
