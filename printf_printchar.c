#include "ft_printf.h"
#include "libft/libft.h"
#include <unistd.h>

int	printchar(char c, t_opts opts)
{
	if (!opts.left)
		printf_pad(opts, opts.minwidth - 1);
	ft_putchar_fd(c, STDOUT_FILENO);
	if (opts.left)
		printf_pad(opts, opts.minwidth - 1);
	return (ft_max(1, opts.minwidth));
}
