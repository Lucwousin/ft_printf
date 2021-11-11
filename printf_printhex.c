#include "ft_printf.h"
#include "libft/libft.h"
#include <unistd.h>

static void	prefix_alt(char **str)
{
	char	*joined;

	joined = ft_strjoin("0x", *str);
	if (!joined)
		return ;
	free(*str);
	*str = joined;
}

int	printhex(unsigned n, t_opts opts, int capitalize)
{
	char	*nbr_str;
	size_t	length;

	nbr_str = printf_ltoa_base(n, 16, opts);
	if (!nbr_str)
		return (0);
	if (opts.pound)
		prefix_alt(&nbr_str);
	if (capitalize)
		ft_strtoupper(nbr_str);
	length = ft_strlen(nbr_str);
	if (opts.zero)
		opts.zero = 0;
	if (!opts.left)
		printf_pad(opts, opts.minwidth - length);
	write(STDOUT_FILENO, nbr_str, length);
	if (opts.left)
		printf_pad(opts, opts.minwidth - length);
	free(nbr_str);
	return (ft_max(length, opts.minwidth));
}