#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <float.h>

int	main(void)
{
	short s = SHRT_MAX;
	int i = INT_MAX;
	long l = LONG_MAX;
	float f = FLT_MAX;
	double d = DBL_MAX;

	// printf("s: ");
	// scanf("%hd", &s);
	// printf("i: ");
	// scanf("%d", &i);
	// printf("l: ");
	// scanf("%ld", &l);
	// printf("f: ");
	// scanf("%f", &f);
	// printf("d: ");
	// scanf("%lf", &d);

	printf("s+10*l = %ld\n", (long)s+(l * 10));
	printf("(s+i)*l = %ld\n", (long)((int)s+i)*l);
	printf("(s+i)*l+f = %f\n", (float)((long)((int)s+i)*l)+f);
	printf("s/f + sin(f) = %f\n", (double)((float)s/f) + sin((double)f));
	printf("l+1.5f = %f\n", (float)l+1.5f);
	printf("i<10 = %d\n", i<10);
	printf("d * 3.14159 = %f\n", d * 3.14159);
}