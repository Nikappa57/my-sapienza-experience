static int	ft_isalpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

static int	ft_islower(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

static int	get_nbr(char c)
{
	int result;
	if (!ft_isalpha(c))
		return (0);
	if (ft_islower(c))
		c -= 32;
	result = (int)c - 64;
	while (result > 9)
		result -= 9;
	return (result);
}

int	sum_digits(int nbr)
{
	int	sum;

	do
	{
		sum = 0;
		while (nbr)
		{
			sum += nbr % 10;
			nbr /= 10;
		}
		nbr = sum;
	}while (sum >= 10 && sum != 11 && sum != 22);
	return (sum);
}

int	destiny_numbers(char *name)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (name[i] != '\0')
		sum += get_nbr(name[i++]);
	return (sum_digits(sum));
}