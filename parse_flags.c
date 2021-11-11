#include "ft_printf.h"

static void	set_zero(t_opts *opts)
{
	if (!opts->left)
		opts->zero = 1;
}

static void	set_left(t_opts *opts)
{
	opts->left = 1;
	opts->zero = 0;
}

static void	set_space(t_opts *opts)
{
	if (!opts->sign)
		opts->space = 1;
}

static void	set_sign(t_opts *opts)
{
	opts->sign = 1;
	opts->space = 0;
}

void	parse_flags(const char **str, t_opts *opts)
{
	const char	*s;

	s = *str;
	while (*s)
	{
		if (*s == '#')
			opts->pound = 1;
		else if (*s == '0')
			set_zero(opts);
		else if (*s == '-')
			set_left(opts);
		else if (*s == ' ')
			set_space(opts);
		else if (*s == '+')
			set_sign(opts);
		else
			break;
		++s;
	}
	*str = s;
}