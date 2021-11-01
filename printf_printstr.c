#include "libft/libft.h"
#include <unistd.h>

int	printstr(const char *str)
{
	size_t	length;

	if (!str)
	{
		write(STDOUT_FILENO, "(null)", 6);
		return (6);
	}
	length = ft_strlen(str);
	write(STDOUT_FILENO, str, length);
	return (length);
}
