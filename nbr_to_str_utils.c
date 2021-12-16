#define BASE_CHARS "0123456789abcdef"

unsigned long	to_uns(long nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	else
		return (nbr);
}

int	length_in_base(unsigned long nbr, int base)
{
	int	n;

	if (nbr == 0)
		return (1);
	n = 0;
	while (nbr != 0)
	{
		nbr /= base;
		++n;
	}
	return (n);
}

void	write_number(char *str, unsigned long nbr, int base, int length)
{
	int	base_index;

	while (length > 0)
	{
		--length;
		base_index = nbr % base;
		str[length] = BASE_CHARS[base_index];
		nbr /= base;
	}
}
