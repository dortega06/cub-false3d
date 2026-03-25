int	ft_countnumhexa(long long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

int	ft_countnum(long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_countwords(const char *s, char c)
{
	int	i;
	int	word;
	int	count;

	i = 0;
	count = 0;
	word = 1;
	while (s[i])
	{
		if (s[i] != c && word)
		{
			count++;
			word = 0;
		}
		else if (s[i] == c)
			word = 1;
		i++;
	}
	return (count);
}
