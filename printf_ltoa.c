#include "ft_printf_internal.h"
#include "libft/libft.h"

static void	add_signchar(char *str, int negative, int space)
{
	if (negative)
		str[0] = '-';
	else if (space)
		str[0] = ' ';
	else
		str[0] = '+';
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

	num_length = length_in_base(to_uns(nbr), base);
	add_sign = should_add_sign(nbr, base, opts);
	num_length = ft_max(opts.precision, num_length);
	if (base == 16 && opts.pound)
		num_length += 2;
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
	write_number(str, to_uns(nbr), base, num_length);
	if (add_sign)
		add_signchar(str, nbr < 0, opts.space);
	return (str);
}
