#include "ft_printf.h"
#include <unistd.h>

int	print_type(char c, t_opts options, va_list args)
{
	if (c == 'c')
		return (printchar((char) va_arg(args, int), options));
	if (c == 's')
		return (printstr(va_arg(args, char *), options));
	if (c == 'p')
		return (printptr(va_arg(args, void *), options));
	if (c == 'd' || c == 'i')
		return (printnbr(va_arg(args, int), options));
	if (c == 'u')
		return (printnbr(va_arg(args, unsigned int), options));
	if (c == 'x')
		return (printhex(va_arg(args, unsigned int), options, 0));
	if (c == 'X')
		return (printhex(va_arg(args, unsigned int), options, 1));
	if (c == '%')
		return (printchar('%', options));
	return (0);
}

int	insert_conversion(const char **str, va_list args)
{
	t_opts	options;
	int		printed;

	options = parse_options(str, args);
	printed = print_type(**str, options, args);
	(*str)++;
	return (printed);
}

/**
 * Print characters from str, until either a '%' or a '\0' is reached
 * This function increments the pointer in str to the '%' or '\0'
 * @return The amount of characters were printed.
 */
int	print_until_percent(const char **str)
{
	const char	*s;
	size_t		count;

	s = *str;
	count = 0;
	while (s[count] && s[count] != '%')
		++count;
	write(STDOUT_FILENO, s, count);
	*str += count;
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	printed;

	printed = 0;
	va_start(args, str);
	while (1)
	{
		if (*str == '\0')
			break ;
		if (*str != '%')
			printed += print_until_percent(&str);
		else
		{
			++str;
			printed += insert_conversion(&str, args);
		}
	}
	va_end(args);
	return (printed);
}
