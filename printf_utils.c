#include "ft_printf.h"
#include "libft/libft.h"
#include <unistd.h>

void	printf_pad(t_opts opts, int count)
{
	char	c;

	c = ' ';
	if (opts.zero && !opts.left)
		c = '0';
	while (count > 0)
	{
		ft_putchar_fd(c, STDOUT_FILENO);
		--count;
	}
}