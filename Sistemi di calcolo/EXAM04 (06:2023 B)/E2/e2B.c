#include "e2B.h"

int getBalanceMovements(const char* fname, int min, int max, int * bal)
{
	FILE	*f;
	char	type;
	int		val;
	int		day;
	int		count;

	f = NULL;
	if ((f = fopen(fname, "r")) == NULL)
		goto ERR;
	*bal = 0;
	count = 0;
	while (fscanf(f, "%d|%c|%d\n", &day, &type, &val) == 3)
	{
		if ((day < min) || (day > max))
			continue ;
		*bal +=  type == '+' ? val : -val;
		count++;
	}
	if (ferror(f))
		goto ERR;
	fclose(f);
	return (count);

ERR:
	if (f)
		fclose(f);
	return (-1);
}
