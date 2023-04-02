void	vec_integral(float *v, int n)
{
	if (n < 2)
		return ;
	vec_integral(v, n - 1);
	v[n - 1] += v[n - 2];
}