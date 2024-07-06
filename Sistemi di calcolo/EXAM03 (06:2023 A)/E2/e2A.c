#include "e2A.h"

int examStats(const char *fname, int *min, int *max, float *avg)
{
	FILE *f = NULL;
	int sum = 0, i = 0, val;
	char tmp[256 + 1];

	if ((f = fopen(fname, "r")) == NULL)
		goto ERR;

	while (fscanf(f, "%256[^-]-%256[^-]-%d\n", tmp, tmp, &val) == 3)
	{
		if (val < 18)
			continue ;
		if (!i++)
			*min = *max = val;
		else
		{
			if (val < *min)
				*min = val;
			if (val > *max)
				*max = val;
		}
		sum += val;
	}
	if (i>0)
		*avg = (float)sum / (float)i;
	else
		*max = *min = *avg = 0;

	fclose(f);
	return (i);

ERR:
	if (f)
		fclose(f);
	return (-1);
}