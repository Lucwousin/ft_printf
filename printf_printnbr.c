#include "libft/libft.h"
#define BASE_CHARS "0123456789abcdef"

static int	length_in_base(long nbr, int base)
{
	int	n;

	n = 0;
	while (nbr != 0)
	{
		nbr /= base;
		++n;
	}
	return (n);
}

static void	add_signchar(char *str, int negative)
{
	if (negative)
		str[0] = '-';
	else
		str[0] = '+';
}

static void	write_number(char *str, long nbr, int base, int length, int sign)
{
	int	base_index;
	int	negative;

	negative = nbr < 0;
	sign |= negative;
	while (length > 0)
	{
		--length;
		if (length == 0 && sign)
			add_signchar(str, negative);
		else
		{
			base_index = ft_abs(nbr % base);
			str[length] = BASE_CHARS[base_index];
			nbr /= base;
		}
	}
}

char	*printf_ltoa_base(long nbr, int base, int precision, int sign)
{
	char	*str;
	int		num_length;
	size_t	str_length;

	num_length = length_in_base(nbr, base);
	if (sign || nbr < 0)
		++num_length;
	str_length = ft_max(precision, num_length);
	str = malloc((str_length + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[str_length] = '\0';
	write_number(str, nbr, base, str_length, sign);
	return (str);
}