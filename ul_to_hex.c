#include "ft_printf.h"
#include "libft/libft.h"

char	*ul_to_hex(unsigned long nbr, t_opts opts)
{
	char	*str;
	int		num_length;

	num_length = length_in_base(nbr, 16);
	num_length = ft_max(opts.precision, num_length);
	if (opts.pound)
		num_length += 2;
	if (opts.precision >= 0 && opts.zero)
		opts.zero = 0;
	if (opts.zero)
		num_length = ft_max(opts.minwidth, num_length);
	str = malloc((num_length + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[num_length] = '\0';
	write_number(str, nbr, 16, num_length);
	return (str);
}
