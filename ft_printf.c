#include <stdarg.h>
#include <unistd.h>

int	insert_conversion(char **str, va_list args)
{
	t_opts	options;

	options = parse_options(str, args);
	return (0);
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
	return count;
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	printed;

	va_start(args, str);
	while (1)
	{
		if (*str == '\0')
			return (printed);
		if (*str != '%')
			printed += print_until_percent(&str);
		else
		{
			++str;
			printed += insert_conversion(&str, args);
		}
	}
}
