float	product(float vec[], int n)
{
	if (n == 0)
		return (1);
	return (*vec * product(vec + 1, n - 1));
}