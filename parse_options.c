#include "ft_printf.h"
#include "libft/libft.h"

void	initialize_options(t_opts *opts)
{
	opts->pound = 0;
	opts->zero = 0;
	opts->left = 0;
	opts->space = 0;
	opts->sign = 0;
	opts->minwidth = 0;
	opts->precision = -1;
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
			opts->zero = 1;
		else if (*s == '-')
			opts->left = 1;
		else if (*s == ' ')
			opts->space = 1;
		else if (*s == '+')
			opts->sign = 1;
		else
			break;
		++s;
	}
	*str = s;
}

int	parse_number(const char **str, va_list args)
{
	const char	*s;
	int			retval;

	s = *str;
	if (*s == '*')
	{
		retval = va_arg(args, int);
		++s;
	}
	else
	{
		retval = 0;
		while (ft_isdigit(*s))
		{
			retval *= 10;
			retval += *s - '0';
			++s;
		}
	}
	*str = s;
	return (retval);
}

t_opts	parse_options(const char **str, va_list args)
{
	t_opts		opts;

	initialize_options(&opts);
	parse_flags(str, &opts);
	if (ft_isdigit(**str) || **str == '*')
	{
		opts.minwidth = parse_number(str, args);
		if (opts.minwidth < 0)
		{
			opts.minwidth *= -1;
			opts.left = 1;
		}
	}
	if (**str == '.')
	{
		++(*str);
		opts.precision = parse_number(str, args);
	}
	return (opts);
}