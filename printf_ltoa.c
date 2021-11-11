#include "ft_printf.h"
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

static void	add_signchar(char *str, int negative, int space)
{
	if (negative)
		str[0] = '-';
	else if (space)
		str[0] = ' ';
	else
		str[0] = '+';
}

static void	write_number(char *str, long nbr, int base, int length)
{
	int	base_index;

	while (length > 0)
	{
		--length;
		base_index = ft_abs(nbr % base);
		str[length] = BASE_CHARS[base_index];
		nbr /= base;
	}
}

static int	should_add_sign(long nbr, int base, t_opts opts)
{
	return (base != 16 && (opts.sign || opts.space || nbr < 0));
}

char	*printf_ltoa_base(long nbr, int base, t_opts opts)
{
	char	*str;
	int		num_length;
	int		add_sign;

	num_length = length_in_base(nbr, base);
	add_sign = should_add_sign(nbr, base, opts);
	num_length = ft_max(opts.precision, num_length);
	if (add_sign)
		num_length++;
	if (opts.precision >= 0 && opts.zero)
		opts.zero = 0;
	if (opts.zero)
		num_length = ft_max(opts.minwidth, num_length);
	str = malloc((num_length + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[num_length] = '\0';
	write_number(str, nbr, base, num_length);
	if (add_sign)
		add_signchar(str, nbr < 0, opts.space);
	return (str);
}